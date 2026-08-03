#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/check-if-any-element-has-prime-frequency.h"

namespace leetcode::problem_3591 {
namespace {

class CheckIfAnyElementHasPrimeFrequencyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CheckIfAnyElementHasPrimeFrequencySolution solution_;
};

TEST_P(CheckIfAnyElementHasPrimeFrequencyTest, Example1) {
  std::vector<int> nums{1, 2, 3, 4, 5, 4};
  EXPECT_EQ(solution_.checkPrimeFrequency(nums), true);
}

TEST_P(CheckIfAnyElementHasPrimeFrequencyTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.checkPrimeFrequency(nums), false);
}

TEST_P(CheckIfAnyElementHasPrimeFrequencyTest, Example3) {
  std::vector<int> nums{2, 2, 2, 4, 4};
  EXPECT_EQ(solution_.checkPrimeFrequency(nums), true);
}

TEST_P(CheckIfAnyElementHasPrimeFrequencyTest, SingleElementFrequencyOneNotPrime) {
  std::vector<int> nums{7};
  EXPECT_EQ(solution_.checkPrimeFrequency(nums), false);
}

TEST_P(CheckIfAnyElementHasPrimeFrequencyTest, FrequencyFourNotPrime) {
  std::vector<int> nums{1, 1, 1, 1};
  EXPECT_EQ(solution_.checkPrimeFrequency(nums), false);
}

TEST_P(CheckIfAnyElementHasPrimeFrequencyTest, PrimeFrequencyFive) {
  std::vector<int> nums{3, 3, 3, 3, 3};
  EXPECT_EQ(solution_.checkPrimeFrequency(nums), true);
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfAnyElementHasPrimeFrequencyTestSuites,
    CheckIfAnyElementHasPrimeFrequencyTest,
    ::testing::ValuesIn(
        CheckIfAnyElementHasPrimeFrequencySolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3591
