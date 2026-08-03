#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-number-of-operations-with-the-same-score-i.h"

namespace leetcode::problem_3038 {

class MaximumNumberOfOperationsWithTheSameScoreITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfOperationsWithTheSameScoreISolution solution_;
};

TEST_P(MaximumNumberOfOperationsWithTheSameScoreITest, Example1) {
  std::vector<int> nums{3, 2, 1, 4, 5};
  EXPECT_EQ(solution_.maxOperations(nums), 2);
}

TEST_P(MaximumNumberOfOperationsWithTheSameScoreITest, Example2) {
  std::vector<int> nums{1, 5, 3, 3, 4, 1, 3, 2, 2, 3};
  EXPECT_EQ(solution_.maxOperations(nums), 2);
}

TEST_P(MaximumNumberOfOperationsWithTheSameScoreITest, Example3) {
  std::vector<int> nums{5, 3};
  EXPECT_EQ(solution_.maxOperations(nums), 1);
}

TEST_P(MaximumNumberOfOperationsWithTheSameScoreITest, SelfAuthoredAllSamePair) {
  std::vector<int> nums{1, 1, 1, 1, 1, 1};
  EXPECT_EQ(solution_.maxOperations(nums), 3);
}

TEST_P(MaximumNumberOfOperationsWithTheSameScoreITest, SelfAuthoredStopAtDifferent) {
  std::vector<int> nums{2, 2, 3, 3, 2, 2};
  EXPECT_EQ(solution_.maxOperations(nums), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfOperationsWithTheSameScoreITestSuite,
    MaximumNumberOfOperationsWithTheSameScoreITest,
    ::testing::ValuesIn(
        MaximumNumberOfOperationsWithTheSameScoreISolution().getStrategyNames()));

}  // namespace leetcode::problem_3038
