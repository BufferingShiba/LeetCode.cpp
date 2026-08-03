#include "leetcode/problems/find-lucky-integer-in-an-array.h"

#include <unordered_map>

namespace leetcode {
namespace problem_1394 {

namespace {

int findLuckyImpl(std::vector<int>& arr) {
  std::unordered_map<int, int> freq;
  for (int v : arr) {
    ++freq[v];
  }
  int ans = -1;
  for (const auto& kv : freq) {
    if (kv.first == kv.second) {
      ans = std::max(ans, kv.first);
    }
  }
  return ans;
}

}  // namespace

FindLuckyIntegerInAnArraySolution::FindLuckyIntegerInAnArraySolution() {
  setMetaInfo({.id = 1394,
               .title = "Find Lucky Integer in an Array",
               .url = "https://leetcode.com/problems/find-lucky-integer-in-an-array/"});
  registerStrategy({.name = "HashTableCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Counting"}},
                   findLuckyImpl);
}

int FindLuckyIntegerInAnArraySolution::findLucky(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1394
}  // namespace leetcode
