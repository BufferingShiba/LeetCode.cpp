#include <gtest/gtest.h>

#include "leetcode/problems/find-maximum-area-of-a-triangle.h"

class FindMaximumAreaOfATriangleTest : public ::testing::TestWithParam<std::string> {
 protected:
  leetcode::problem_3588::FindMaximumAreaOfATriangleSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FindMaximumAreaOfATriangleTest, Example1) {
  std::vector<std::vector<int>> coords = {{1, 1}, {1, 2}, {3, 2}, {3, 3}};
  EXPECT_EQ(solution.maxArea(coords), 2);
}

TEST_P(FindMaximumAreaOfATriangleTest, Example2) {
  std::vector<std::vector<int>> coords = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(solution.maxArea(coords), -1);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredHorizontalTriangle) {
  std::vector<std::vector<int>> coords = {{1, 1}, {5, 1}, {3, 4}};
  // base=4, height=3, area=6, 2*A=12
  EXPECT_EQ(solution.maxArea(coords), 12);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredVerticalTriangle) {
  std::vector<std::vector<int>> coords = {{1, 1}, {1, 5}, {4, 3}};
  // base=4 (vertical), height=3 (horizontal), area=6, 2*A=12
  EXPECT_EQ(solution.maxArea(coords), 12);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredAllCollinearHorizontal) {
  std::vector<std::vector<int>> coords = {{1, 1}, {3, 1}, {5, 1}};
  EXPECT_EQ(solution.maxArea(coords), -1);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredAllCollinearVertical) {
  std::vector<std::vector<int>> coords = {{1, 1}, {1, 3}, {1, 5}};
  EXPECT_EQ(solution.maxArea(coords), -1);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredTwoPointsOnly) {
  std::vector<std::vector<int>> coords = {{1, 1}, {2, 2}};
  EXPECT_EQ(solution.maxArea(coords), -1);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredSinglePoint) {
  std::vector<std::vector<int>> coords = {{1, 1}};
  EXPECT_EQ(solution.maxArea(coords), -1);
}

TEST_P(FindMaximumAreaOfATriangleTest, SelfAuthoredLargeCoordinates) {
  std::vector<std::vector<int>> coords = {{1, 1}, {1000000, 1}, {500000, 1000000}};
  // base = 999999, height = 999999, 2*A = 999999 * 999999 = 999998000001
  long long expected = 999999LL * 999999;
  EXPECT_EQ(solution.maxArea(coords), expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, FindMaximumAreaOfATriangleTest,
                         ::testing::ValuesIn(leetcode::problem_3588::FindMaximumAreaOfATriangleSolution()
                                                 .getStrategyNames()));
