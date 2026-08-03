#include "leetcode/problems/find-maximum-number-of-non-intersecting-substrings.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3557 {

namespace {

int maxSubstringsImpl(std::string word) {
  const int n = static_cast<int>(word.size());
  if (n < 4) {
    return 0;
  }

  std::vector<std::vector<int>> pos(26);
  for (int i = 0; i < n; ++i) {
    pos[word[i] - 'a'].push_back(i);
  }

  int ans = 0;
  int last_end = -1;

  for (int r = 0; r < n; ++r) {
    const int c = word[r] - 'a';
    const auto& vec = pos[c];
    // 找到 ≤ r-3 的最大出现位置
    const int target = r - 3;
    auto it = std::upper_bound(vec.begin(), vec.end(), target);
    if (it != vec.begin()) {
      const int l = *(--it);
      // 该区间与已选区间不重叠
      if (l > last_end) {
        ++ans;
        last_end = r;
      }
    }
  }

  return ans;
}

}  // namespace

FindMaximumNumberOfNonIntersectingSubstringsSolution::FindMaximumNumberOfNonIntersectingSubstringsSolution() {
  setMetaInfo({.id = 3557,
               .title = "Find Maximum Number of Non Intersecting Substrings",
               .url = "https://leetcode.com/problems/find-maximum-number-of-non-intersecting-substrings/"});
  registerStrategy({.name = "Greedy",
                     .expected = "Accepted",
                     .time_complexity = "O(n log n)",
                     .space_complexity = "O(n)",
                     .tags = {"Hash Table", "String", "Greedy"}},
                   maxSubstringsImpl);
}

int FindMaximumNumberOfNonIntersectingSubstringsSolution::maxSubstrings(std::string word) {
  return getSolution()(std::move(word));
}

}  // namespace problem_3557
}  // namespace leetcode
