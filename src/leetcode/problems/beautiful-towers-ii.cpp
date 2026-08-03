#include "leetcode/problems/beautiful-towers-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_2866 {

namespace {

long long maximumSumOfHeightsImpl(std::vector<int>& maxHeights) {
  const int n = static_cast<int>(maxHeights.size());
  if (n == 0) return 0;

  // pre[i]: max sum of non-decreasing heights[0..i] with heights[i] = maxHeights[i]
  // (array is a peak at i, considering only the left part).
  std::vector<long long> pre(n, 0);
  std::vector<int> st;  // indices with strictly increasing maxHeights
  long long acc = 0;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && maxHeights[st.back()] >= maxHeights[i]) {
      int idx = st.back();
      st.pop_back();
      long long width = idx - (st.empty() ? -1LL : st.back());
      acc -= static_cast<long long>(maxHeights[idx]) * width;
    }
    st.push_back(i);
    long long prev = st.size() >= 2 ? st[st.size() - 2] : -1LL;
    acc += static_cast<long long>(maxHeights[i]) * (i - prev);
    pre[i] = acc;
  }

  // suf[i]: max sum of non-increasing heights[i..n-1] with heights[i] = maxHeights[i]
  // (array is a peak at i, considering only the right part).
  std::vector<long long> suf(n, 0);
  st.clear();
  acc = 0;
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && maxHeights[st.back()] >= maxHeights[i]) {
      int idx = st.back();
      st.pop_back();
      long long width = (st.empty() ? n : st.back()) - idx;
      acc -= static_cast<long long>(maxHeights[idx]) * width;
    }
    st.push_back(i);
    long long nxt = st.size() >= 2 ? st[st.size() - 2] : n;
    acc += static_cast<long long>(maxHeights[i]) * (nxt - i);
    suf[i] = acc;
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    // Peak at i; the peak height is counted in both pre[i] and suf[i], subtract once.
    ans = std::max(ans, pre[i] + suf[i] - maxHeights[i]);
  }
  return ans;
}

}  // namespace

BeautifulTowersIiSolution::BeautifulTowersIiSolution() {
  this->setMetaInfo({
      .id = 2866,
      .title = "Beautiful Towers II",
      .url =
          "https://leetcode.com/problems/beautiful-towers-ii/",
  });
  this->registerStrategy(
      {
          .name = "MonotonicStack",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(n)",
          .tags = {"Array", "Stack", "MonotonicStack"},
      },
      maximumSumOfHeightsImpl);
}

long long BeautifulTowersIiSolution::call(std::vector<int>& maxHeights) {
  return this->getSolution()(maxHeights);
}

}  // namespace leetcode::problem_2866
