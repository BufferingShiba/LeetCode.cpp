#include "leetcode/problems/maximum-height-of-a-triangle.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3200 {

class MaximumHeightOfATriangleTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumHeightOfATriangleSolution solution;
};

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximumHeightOfATriangleTest,
    ::testing::ValuesIn(MaximumHeightOfATriangleSolution().getStrategyNames()));

// ===== Official Example 1 (from LeetCode) =====
// Input:  red = 2, blue = 4
// Output: 3
TEST_P(MaximumHeightOfATriangleTest, OfficialExample1) {
  int result = solution.maxHeightOfTriangle(2, 4);
  EXPECT_EQ(3, result);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  red = 2, blue = 1
// Output: 2
TEST_P(MaximumHeightOfATriangleTest, OfficialExample2) {
  int result = solution.maxHeightOfTriangle(2, 1);
  EXPECT_EQ(2, result);
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  red = 1, blue = 1
// Output: 1
TEST_P(MaximumHeightOfATriangleTest, OfficialExample3) {
  int result = solution.maxHeightOfTriangle(1, 1);
  EXPECT_EQ(1, result);
}

// ===== Official Example 4 (from LeetCode) =====
// Input:  red = 10, blue = 1
// Output: 2
TEST_P(MaximumHeightOfATriangleTest, OfficialExample4) {
  int result = solution.maxHeightOfTriangle(10, 1);
  EXPECT_EQ(2, result);
}

}  // namespace problem_3200
}  // namespace leetcode
