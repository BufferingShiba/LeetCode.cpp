#include "leetcode/problems/beautiful-towers-i.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2865 {

namespace {

long long maximumSumOfHeightsImpl(std::vector<int>& heights) {
  const int n = static_cast<int>(heights.size());
  // left[i] = max sum of towers in [0..i] with peak at i (peak = heights[i]).
  std::vector<long long> left(n);
  {
    // Monotonic non-decreasing stack of indices whose heights decrease toward stack top.
    std::vector<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && heights[st.back()] >= heights[i]) {
        st.pop_back();
      }
      int last = st.empty() ? -1 : st.back();
      long long base = last >= 0 ? left[last] : 0LL;
      left[i] = base + static_cast<long long>(heights[i]) * (i - last);
      st.push_back(i);
    }
  }

  // right[i] = max sum of towers in [i..n-1] with peak at i.
  std::vector<long long> right(n);
  {
    std::vector<int> st;
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && heights[st.back()] >= heights[i]) {
        st.pop_back();
      }
      int last = st.empty() ? n : st.back();
      long long base = last < n ? right[last] : 0LL;
      right[i] = base + static_cast<long long>(heights[i]) * (last - i);
      st.push_back(i);
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = std::max(ans, left[i] + right[i] - static_cast<long long>(heights[i]));
  }
  return ans;
}

}  // namespace

long long BeautifulTowersISolution::maximumSumOfHeights(std::vector<int>& heights) {
  return getSolution()(heights);
}

BeautifulTowersISolution::BeautifulTowersISolution() {
  setMetaInfo({.id = 2865,
               .title = "Beautiful Towers I",
               .url = "https://leetcode.com/problems/beautiful-towers-i/"});
  registerStrategy({.name = "MonotonicStack",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Stack", "Monotonic Stack"}},
                   maximumSumOfHeightsImpl);
}

}  // namespace problem_2865
}  // namespace leetcode
