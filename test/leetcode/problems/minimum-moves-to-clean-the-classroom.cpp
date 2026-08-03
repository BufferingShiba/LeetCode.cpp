#include "leetcode/problems/minimum-moves-to-clean-the-classroom.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_3568 {

class MinimumMovesToCleanTheClassroomTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumMovesToCleanTheClassroom solution;
};

TEST_P(MinimumMovesToCleanTheClassroomTest, Example1) {
  std::vector<std::string> classroom = {"S.", "XL"};
  EXPECT_EQ(solution.minMoves(classroom, 2), 2);
}

TEST_P(MinimumMovesToCleanTheClassroomTest, Example2) {
  std::vector<std::string> classroom = {"LS", "RL"};
  EXPECT_EQ(solution.minMoves(classroom, 4), 3);
}

TEST_P(MinimumMovesToCleanTheClassroomTest, Example3) {
  std::vector<std::string> classroom = {"L.S", "RXL"};
  EXPECT_EQ(solution.minMoves(classroom, 3), -1);
}

TEST_P(MinimumMovesToCleanTheClassroomTest, SingleLitterAdjacent) {
  std::vector<std::string> classroom = {"SL"};
  EXPECT_EQ(solution.minMoves(classroom, 1), 1);
}

TEST_P(MinimumMovesToCleanTheClassroomTest, ImpossibleBlocked) {
  std::vector<std::string> classroom = {"SX", "XL"};
  EXPECT_EQ(solution.minMoves(classroom, 5), -1);
}

TEST_P(MinimumMovesToCleanTheClassroomTest, NeedResetToReachFarLitter) {
  // S at (1,0), L at (0,2), R at (0,0). With energy 2, S->L directly costs 3>
  // 2, so must visit R to refill then reach L: S(1,0)->(1,1)->(0,1)->R(0,0)
  // ... picking a minimal route.
  std::vector<std::string> classroom = {"R.L", "S.."};
  EXPECT_EQ(solution.minMoves(classroom, 2), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumMovesToCleanTheClassroomTest, MinimumMovesToCleanTheClassroomTest,
    ::testing::ValuesIn(MinimumMovesToCleanTheClassroom().getStrategyNames()));

}  // namespace leetcode::problem_3568
