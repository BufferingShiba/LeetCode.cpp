#include "leetcode/problems/largest-rectangle-in-histogram.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_84 {
namespace {

int largestRectangleAreaImpl(std::vector<int>& heights) {
  std::vector<int> st;
  st.reserve(heights.size());
  int maxArea = 0;

  for (int i = 0; i <= static_cast<int>(heights.size()); ++i) {
    int curHeight = (i == static_cast<int>(heights.size())) ? 0 : heights[i];
    while (!st.empty() && heights[st.back()] > curHeight) {
      int h = heights[st.back()];
      st.pop_back();
      int left = st.empty() ? -1 : st.back();
      int width = i - left - 1;
      maxArea = std::max(maxArea, h * width);
    }
    st.push_back(i);
  }
  return maxArea;
}

}  // namespace

LargestRectangleInHistogramSolution::LargestRectangleInHistogramSolution() {
  setMetaInfo({.id = 84,
               .title = "Largest Rectangle in Histogram",
               .url = "https://leetcode.com/problems/largest-rectangle-in-histogram/"});

  registerStrategy(
      {.name = "monotonic-stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Monotonic Stack"},
       .notes =
           "Maintain a strictly increasing stack of indices. When a shorter bar "
           "is encountered, pop the taller bars; for each popped bar, its width "
           "is bounded by the new top (left) and the current index (right)."},
      largestRectangleAreaImpl);
}

}  // namespace problem_84
}  // namespace leetcode
