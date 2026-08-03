#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/relocate-marbles.h"

namespace leetcode {
namespace problem_2766 {

class RelocateMarblesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RelocateMarblesSolution solution;
};

TEST_P(RelocateMarblesTest, Example1) {
  std::vector<int> nums = {1, 6, 7, 8};
  std::vector<int> moveFrom = {1, 7, 2};
  std::vector<int> moveTo = {2, 9, 5};
  std::vector<int> expected = {5, 6, 8, 9};
  EXPECT_EQ(solution.relocateMarbles(nums, moveFrom, moveTo), expected);
}

TEST_P(RelocateMarblesTest, Example2) {
  std::vector<int> nums = {1, 1, 3, 3};
  std::vector<int> moveFrom = {1, 3};
  std::vector<int> moveTo = {2, 2};
  std::vector<int> expected = {2};
  EXPECT_EQ(solution.relocateMarbles(nums, moveFrom, moveTo), expected);
}

TEST_P(RelocateMarblesTest, SelfAuthoredNoMoves) {
  std::vector<int> nums = {5, 2, 2, 7};
  std::vector<int> moveFrom = {};
  std::vector<int> moveTo = {};
  std::vector<int> expected = {2, 5, 7};
  EXPECT_EQ(solution.relocateMarbles(nums, moveFrom, moveTo), expected);
}

TEST_P(RelocateMarblesTest, SelfAuthoredSelfMove) {
  std::vector<int> nums = {3, 3, 1};
  std::vector<int> moveFrom = {3};
  std::vector<int> moveTo = {3};
  std::vector<int> expected = {1, 3};
  EXPECT_EQ(solution.relocateMarbles(nums, moveFrom, moveTo), expected);
}

TEST_P(RelocateMarblesTest, SelfAuthoredMoveIntoAlreadyOccupied) {
  std::vector<int> nums = {2, 5};
  std::vector<int> moveFrom = {2};
  std::vector<int> moveTo = {5};
  std::vector<int> expected = {5};
  EXPECT_EQ(solution.relocateMarbles(nums, moveFrom, moveTo), expected);
}

INSTANTIATE_TEST_SUITE_P(RelocateMarblesTestSuite, RelocateMarblesTest,
                         ::testing::ValuesIn(RelocateMarblesSolution().getStrategyNames()));

}  // namespace problem_2766
}  // namespace leetcode
