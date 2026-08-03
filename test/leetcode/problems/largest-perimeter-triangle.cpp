#include <gtest/gtest.h>

#include "leetcode/problems/largest-perimeter-triangle.h"

#include <string>
#include <vector>

namespace leetcode::problem_976 {

class LargestPerimeterTriangleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestPerimeterTriangleSolution solution;
};

TEST_P(LargestPerimeterTriangleTest, Example1) {
  std::vector<int> nums{2, 1, 2};
  EXPECT_EQ(solution.largestPerimeter(nums), 5);
}

TEST_P(LargestPerimeterTriangleTest, Example2) {
  std::vector<int> nums{1, 2, 1, 10};
  EXPECT_EQ(solution.largestPerimeter(nums), 0);
}

TEST_P(LargestPerimeterTriangleTest, SelfAuthored1) {
  std::vector<int> nums{3, 6, 2, 3};
  EXPECT_EQ(solution.largestPerimeter(nums), 8);
}

TEST_P(LargestPerimeterTriangleTest, SelfAuthored2) {
  std::vector<int> nums{1, 1, 1};
  EXPECT_EQ(solution.largestPerimeter(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    LargestPerimeterTriangleTestSuite, LargestPerimeterTriangleTest,
    ::testing::ValuesIn(LargestPerimeterTriangleSolution().getStrategyNames()));

}  // namespace leetcode::problem_976
