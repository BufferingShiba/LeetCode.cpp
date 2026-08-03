#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/even-number-of-knight-moves.h"

namespace leetcode {
namespace problem_3996 {
namespace {

class EvenNumberOfKnightMovesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  EvenNumberOfKnightMovesSolution solution_;
};

TEST_P(EvenNumberOfKnightMovesTest, Example1) {
  std::vector<int> start{1, 1};
  std::vector<int> target{2, 2};
  EXPECT_TRUE(solution_.canReach(start, target));
}

TEST_P(EvenNumberOfKnightMovesTest, Example2) {
  std::vector<int> start{4, 5};
  std::vector<int> target{6, 6};
  EXPECT_FALSE(solution_.canReach(start, target));
}

TEST_P(EvenNumberOfKnightMovesTest, SelfAuthoredSameCell) {
  std::vector<int> start{0, 0};
  std::vector<int> target{0, 0};
  EXPECT_TRUE(solution_.canReach(start, target));
}

INSTANTIATE_TEST_SUITE_P(
    EvenNumberOfKnightMovesTestSuite, EvenNumberOfKnightMovesTest,
    ::testing::ValuesIn(EvenNumberOfKnightMovesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3996
}  // namespace leetcode
