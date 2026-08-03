#include "leetcode/problems/query-kth-smallest-trimmed-number.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2343 {
namespace {

// For a query [k, trim], trim each number to its rightmost `trim` digits and
// find the index of the k-th smallest trimmed number (stable ordering).
// Since all trimmed strings have equal length, lexicographic comparison is
// equivalent to numeric comparison (including leading zeros).
std::vector<int> sortingStrategy(std::vector<std::string>& nums,
                                 std::vector<std::vector<int>>& queries) {
  const int len = static_cast<int>(nums[0].size());
  std::vector<int> answer;
  answer.reserve(queries.size());

  for (const auto& q : queries) {
    const int k = q[0];
    const int trim = q[1];

    std::vector<std::pair<std::string, int>> trimmed;
    trimmed.reserve(nums.size());
    for (std::size_t i = 0; i < nums.size(); ++i) {
      trimmed.emplace_back(nums[i].substr(len - trim), static_cast<int>(i));
    }
    // Stable sort preserves original index order for equal trimmed values,
    // which matches the rule that the lower index is considered smaller.
    std::stable_sort(
        trimmed.begin(), trimmed.end(),
        [](const std::pair<std::string, int>& a,
           const std::pair<std::string, int>& b) {
          return a.first < b.first;
        });
    answer.push_back(trimmed[k - 1].second);
  }
  return answer;
}

}  // namespace

QueryKthSmallestTrimmedNumberSolution::QueryKthSmallestTrimmedNumberSolution() {
  setMetaInfo({.id = 2343,
               .title = "Query Kth Smallest Trimmed Number",
               .url = "https://leetcode.com/problems/query-kth-smallest-trimmed-number/"});
  registerStrategy(
      {"sort per query", "Accepted", "O(q * n * log(n) * trim)",
       "O(n)", {"Array", "String", "Sorting"},
       "For each query, trim each number to rightmost trim digits and stable-sort "
       "them. Equal trimmed values keep original index order (lower index first)."},
      sortingStrategy);
}

}  // namespace problem_2343
}  // namespace leetcode
