#include "leetcode/problems/find-indices-of-stable-mountains.h"

#include <vector>

namespace leetcode {
namespace problem_3285 {

namespace {

std::vector<int> stableMountainsImpl(std::vector<int>& height,
                                     int threshold) {
  std::vector<int> result;
  for (int i = 1; i < static_cast<int>(height.size()); ++i) {
    if (height[i - 1] > threshold) {
      result.push_back(i);
    }
  }
  return result;
}

}  // namespace

FindIndicesOfStableMountainsSolution::FindIndicesOfStableMountainsSolution() {
  setMetaInfo({
      .id = 3285,
      .title = "Find Indices of Stable Mountains",
      .url = "https://leetcode.com/problems/find-indices-of-stable-mountains/",
  });
  registerStrategy(
      {
          .name = "LinearScan",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(1) excluding output",
          .tags = {"Array"},
      },
      stableMountainsImpl);
}

std::vector<int> FindIndicesOfStableMountainsSolution::stableMountains(
    std::vector<int>& height, int threshold) {
  return getSolution()(height, threshold);
}

}  // namespace problem_3285
}  // namespace leetcode
