#include "leetcode/problems/find-x-value-of-array-i.h"

#include <unordered_map>
#include <utility>

namespace leetcode::problem_3524 {

namespace {

std::vector<long long> resultArrayImpl(std::vector<int>& nums, int k) {
  std::vector<long long> result(k, 0);
  std::unordered_map<int, long long> ends;

  for (const int val : nums) {
    const int v = val % k;
    std::unordered_map<int, long long> next;
    for (const auto& [m, cnt] : ends) {
      const int nm = static_cast<int>(1LL * (m * v) % k);
      next[nm] += cnt;
    }
    ++next[v];

    for (const auto& [m, cnt] : next) {
      result[m] += cnt;
    }
    ends = std::move(next);
  }

  return result;
}

}  // namespace

FindXValueOfArrayISolution::FindXValueOfArrayISolution() {
  setMetaInfo({.id = 3524,
               .title = "Find X Value of Array I",
               .url = "https://leetcode.com/problems/find-x-value-of-array-i/"});
  registerStrategy(
      {.name = "dp_mod_distribution",
       .expected = "Accepted",
       .time_complexity = "O(n * k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Math", "Dynamic Programming"}},
      resultArrayImpl);
}

std::vector<long long> FindXValueOfArrayISolution::resultArray(std::vector<int>& nums,
                                                               int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_3524
