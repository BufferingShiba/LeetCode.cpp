#include <gtest/gtest.h>

#include "leetcode/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2023 {
namespace {

using NumberOfPairsOfStringsWithConcatenationEqualToTargetTest =
    ::testing::TestWithParam<std::string>;

class NumberOfPairsOfStringsWithConcatenationEqualToTargetFixture
    : public NumberOfPairsOfStringsWithConcatenationEqualToTargetTest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution solution_;
};

TEST_P(NumberOfPairsOfStringsWithConcatenationEqualToTargetFixture, Example1) {
  std::vector<std::string> nums = {"777", "7", "77", "77"};
  std::string target = "7777";
  EXPECT_EQ(4, solution_.numOfPairs(nums, target));
}

TEST_P(NumberOfPairsOfStringsWithConcatenationEqualToTargetFixture, Example2) {
  std::vector<std::string> nums = {"123", "4", "12", "34"};
  std::string target = "1234";
  EXPECT_EQ(2, solution_.numOfPairs(nums, target));
}

TEST_P(NumberOfPairsOfStringsWithConcatenationEqualToTargetFixture, Example3) {
  std::vector<std::string> nums = {"1", "1", "1"};
  std::string target = "11";
  EXPECT_EQ(6, solution_.numOfPairs(nums, target));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfPairsOfStringsWithConcatenationEqualToTargetStrategies,
    NumberOfPairsOfStringsWithConcatenationEqualToTargetFixture,
    ::testing::ValuesIn(
        NumberOfPairsOfStringsWithConcatenationEqualToTargetSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_2023
}  // namespace leetcode
