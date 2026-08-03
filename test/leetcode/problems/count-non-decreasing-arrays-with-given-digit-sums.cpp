#include "leetcode/problems/count-non-decreasing-arrays-with-given-digit-sums.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3883 {
namespace {

class CountNonDecreasingArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountNonDecreasingArraysWithGivenDigitSumsSolution solution_;
};

TEST_P(CountNonDecreasingArraysTest, Example1) {
  std::vector<int> digitSum = {25, 1};
  EXPECT_EQ(solution_.countArrays(digitSum), 6);
}

TEST_P(CountNonDecreasingArraysTest, Example2) {
  std::vector<int> digitSum = {1};
  EXPECT_EQ(solution_.countArrays(digitSum), 4);
}

TEST_P(CountNonDecreasingArraysTest, Example3) {
  std::vector<int> digitSum = {2, 49, 23};
  EXPECT_EQ(solution_.countArrays(digitSum), 0);
}

TEST_P(CountNonDecreasingArraysTest, ZeroDigitSum) {
  std::vector<int> digitSum = {0, 0, 0};
  EXPECT_EQ(solution_.countArrays(digitSum), 1);
}

TEST_P(CountNonDecreasingArraysTest, RepeatedDigitSumOne) {
  std::vector<int> digitSum = {1, 1};
  // The four values are 1, 10, 100 and 1000; choose a non-decreasing pair.
  EXPECT_EQ(solution_.countArrays(digitSum), 10);
}

INSTANTIATE_TEST_SUITE_P(
    CountNonDecreasingArraysStrategies, CountNonDecreasingArraysTest,
    ::testing::ValuesIn(
        CountNonDecreasingArraysWithGivenDigitSumsSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_3883
}  // namespace leetcode
