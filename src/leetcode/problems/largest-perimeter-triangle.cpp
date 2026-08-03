#include "leetcode/problems/largest-perimeter-triangle.h"

#include <algorithm>

namespace leetcode::problem_976 {

namespace {

int largestPerimeterImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end(), std::greater<int>());
  for (std::size_t i = 2; i < nums.size(); ++i) {
    if (nums[i - 2] < nums[i - 1] + nums[i]) {
      return nums[i - 2] + nums[i - 1] + nums[i];
    }
  }
  return 0;
}

}  // namespace

LargestPerimeterTriangleSolution::LargestPerimeterTriangleSolution() {
  setMetaInfo({.id = 976,
               .title = "Largest Perimeter Triangle",
               .url = "https://leetcode.com/problems/largest-perimeter-triangle/"});
  registerStrategy({.name = "sort-greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Array", "Math", "Greedy", "Sorting"}},
                   largestPerimeterImpl);
}

int LargestPerimeterTriangleSolution::largestPerimeter(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_976
