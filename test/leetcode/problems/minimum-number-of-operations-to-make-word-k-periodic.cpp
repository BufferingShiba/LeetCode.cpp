#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-operations-to-make-word-k-periodic.h"

namespace leetcode {
namespace problem_3137 {

class MinimumNumberOfOperationsToMakeWordKPeriodicTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumNumberOfOperationsToMakeWordKPeriodicSolution solution_;
};

TEST_P(MinimumNumberOfOperationsToMakeWordKPeriodicTest, Example1) {
  EXPECT_EQ(solution_.minimumOperationsToMakeKPeriodic("leetcodeleet", 4), 1);
}

TEST_P(MinimumNumberOfOperationsToMakeWordKPeriodicTest, Example2) {
  EXPECT_EQ(solution_.minimumOperationsToMakeKPeriodic("leetcoleet", 2), 3);
}

TEST_P(MinimumNumberOfOperationsToMakeWordKPeriodicTest, SelfAuthoredAlreadyPeriodic) {
  EXPECT_EQ(solution_.minimumOperationsToMakeKPeriodic("abcabcabc", 3), 0);
}

TEST_P(MinimumNumberOfOperationsToMakeWordKPeriodicTest, SelfAuthoredSingleBlock) {
  EXPECT_EQ(solution_.minimumOperationsToMakeKPeriodic("abcde", 5), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfOperationsToMakeWordKPeriodicTestCases,
    MinimumNumberOfOperationsToMakeWordKPeriodicTest,
    ::testing::ValuesIn(
        MinimumNumberOfOperationsToMakeWordKPeriodicSolution().getStrategyNames()));

}  // namespace problem_3137
}  // namespace leetcode
