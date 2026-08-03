#include "leetcode/problems/maximum-xor-of-two-numbers-in-an-array.h"

#include <unordered_set>

namespace leetcode::problem_421 {

namespace {

int findMaximumXORImpl(std::vector<int>& nums) {
  int result = 0;
  int mask = 0;
  // 从最高位（位30）逐位贪心构建最大异或值。
  for (int bit = 30; bit >= 0; --bit) {
    mask |= (1 << bit);
    std::unordered_set<int> prefixes;
    for (int num : nums) {
      prefixes.insert(num & mask);
    }
    int candidate = result | (1 << bit);
    for (int prefix : prefixes) {
      if (prefixes.count(prefix ^ candidate) > 0) {
        result = candidate;
        break;
      }
    }
  }
  return result;
}

}  // namespace

MaximumXorOfTwoNumbersInAnArraySolution::
    MaximumXorOfTwoNumbersInAnArraySolution() {
  setMetaInfo({.id = 421,
               .title = "Maximum XOR of Two Numbers in an Array",
               .url =
                   "https://leetcode.com/problems/maximum-xor-of-two-numbers-"
                   "in-an-array/"});

  registerStrategy(
      {"greedy-bit-xor",
       "Accepted",
       "O(n * 31)",
       "O(n)",
       {"Array", "Hash Table", "Bit Manipulation", "Trie"},
       "逐位贪心 + 前缀哈希去重，从高到低验证候选异或值可达性"},
      findMaximumXORImpl);
}

int MaximumXorOfTwoNumbersInAnArraySolution::findMaximumXOR(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_421
