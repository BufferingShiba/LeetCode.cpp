#include "leetcode/problems/minimum-number-of-operations-to-move-all-balls-to-each-box.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1769 {

class MinimumNumberOfOperationsToMoveAllBallsToEachBoxTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  boxes = "110"
// Output: [1,1,3]
TEST_P(MinimumNumberOfOperationsToMoveAllBallsToEachBoxTest, OfficialExample1) {
  EXPECT_EQ((std::vector<int>{1, 1, 3}), solution.minOperations("110"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  boxes = "001011"
// Output: [11,8,5,4,3,4]
TEST_P(MinimumNumberOfOperationsToMoveAllBallsToEachBoxTest, OfficialExample2) {
  EXPECT_EQ((std::vector<int>{11, 8, 5, 4, 3, 4}), solution.minOperations("001011"));
}

// ===== Edge case: single box =====
TEST_P(MinimumNumberOfOperationsToMoveAllBallsToEachBoxTest, SingleBox) {
  EXPECT_EQ((std::vector<int>{0}), solution.minOperations("0"));
  EXPECT_EQ((std::vector<int>{0}), solution.minOperations("1"));
}

TEST_P(MinimumNumberOfOperationsToMoveAllBallsToEachBoxTest, AlternatingBoxes) {
  EXPECT_EQ((std::vector<int>{6, 5, 4, 5, 6}), solution.minOperations("10101"));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumNumberOfOperationsToMoveAllBallsToEachBoxTest,
    ::testing::ValuesIn(MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution().getStrategyNames()));

}  // namespace problem_1769
}  // namespace leetcode
