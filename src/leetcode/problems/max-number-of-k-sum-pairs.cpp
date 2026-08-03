#include "leetcode/problems/max-number-of-k-sum-pairs.h"

#include <unordered_map>

namespace leetcode {
namespace problem_1679 {
namespace {

int maxOperationsImpl(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> count;
  int operations = 0;
  for (int num : nums) {
    int complement = k - num;
    if (count[complement] > 0) {
      --count[complement];
      ++operations;
    } else {
      ++count[num];
    }
  }
  return operations;
}

}  // namespace

MaxNumberOfKSumPairsSolution::MaxNumberOfKSumPairsSolution() {
  setMetaInfo(
      {1679, "Max Number of K-Sum Pairs",
       "https://leetcode.com/problems/max-number-of-k-sum-pairs/"});
  registerStrategy(
      {"hash-map-count", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table"}},
      maxOperationsImpl);
}

int MaxNumberOfKSumPairsSolution::maxOperations(std::vector<int>& nums,
                                                int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1679
}  // namespace leetcode
