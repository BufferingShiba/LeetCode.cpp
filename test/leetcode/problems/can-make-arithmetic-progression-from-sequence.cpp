#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/can-make-arithmetic-progression-from-sequence.h"

namespace leetcode::problem_1502 {

class CanMakeArithmeticProgressionFromSequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CanMakeArithmeticProgressionFromSequenceSolution solution_;
};

TEST_P(CanMakeArithmeticProgressionFromSequenceTest, Example1) {
  std::vector<int> arr{3, 5, 1};
  EXPECT_TRUE(solution_.canMakeArithmeticProgression(arr));
}

TEST_P(CanMakeArithmeticProgressionFromSequenceTest, Example2) {
  std::vector<int> arr{1, 2, 4};
  EXPECT_FALSE(solution_.canMakeArithmeticProgression(arr));
}

TEST_P(CanMakeArithmeticProgressionFromSequenceTest, SelfAuthoredTwoElements) {
  std::vector<int> arr{3, 7};
  EXPECT_TRUE(solution_.canMakeArithmeticProgression(arr));
}

TEST_P(CanMakeArithmeticProgressionFromSequenceTest, SelfAuthoredAllSameValues) {
  std::vector<int> arr{2, 2, 2, 2};
  EXPECT_TRUE(solution_.canMakeArithmeticProgression(arr));
}

INSTANTIATE_TEST_SUITE_P(
    CanMakeArithmeticProgressionFromSequenceTests,
    CanMakeArithmeticProgressionFromSequenceTest,
    ::testing::ValuesIn(
        CanMakeArithmeticProgressionFromSequenceSolution().getStrategyNames()));

}  // namespace leetcode::problem_1502
