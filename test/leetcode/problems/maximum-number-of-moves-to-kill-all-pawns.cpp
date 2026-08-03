#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-moves-to-kill-all-pawns.h"

namespace leetcode {
namespace problem_3283 {
namespace {

class MaximumNumberOfMovesToKillAllPawnsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfMovesToKillAllPawnsSolution solution_;
};

TEST_P(MaximumNumberOfMovesToKillAllPawnsTest, Example1) {
  int kx = 1, ky = 1;
  std::vector<std::vector<int>> positions = {{0, 0}};
  EXPECT_EQ(4, solution_.maxMoves(kx, ky, positions));
}

TEST_P(MaximumNumberOfMovesToKillAllPawnsTest, Example2) {
  int kx = 0, ky = 2;
  std::vector<std::vector<int>> positions = {{1, 1}, {2, 2}, {3, 3}};
  EXPECT_EQ(8, solution_.maxMoves(kx, ky, positions));
}

TEST_P(MaximumNumberOfMovesToKillAllPawnsTest, Example3) {
  int kx = 0, ky = 0;
  std::vector<std::vector<int>> positions = {{1, 2}, {2, 4}};
  EXPECT_EQ(3, solution_.maxMoves(kx, ky, positions));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfMovesToKillAllPawnsTestSuite,
    MaximumNumberOfMovesToKillAllPawnsTest,
    ::testing::ValuesIn(MaximumNumberOfMovesToKillAllPawnsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3283
}  // namespace leetcode
