#include <gtest/gtest.h>
#include "leetcode/problems/maximum-difference-between-even-and-odd-frequency-ii.h"

namespace leetcode::problem_3445 {

class MaximumDifferenceBetweenEvenAndOddFrequencyIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution solution_;
};

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyIiTest, Example1) {
  EXPECT_EQ(solution_.maxDifference("12233", 4), -1);
}

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyIiTest, Example2) {
  EXPECT_EQ(solution_.maxDifference("1122211", 3), 1);
}

TEST_P(MaximumDifferenceBetweenEvenAndOddFrequencyIiTest, Example3) {
  EXPECT_EQ(solution_.maxDifference("110", 3), -1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumDifferenceBetweenEvenAndOddFrequencyIi,
    MaximumDifferenceBetweenEvenAndOddFrequencyIiTest,
    ::testing::ValuesIn(
        MaximumDifferenceBetweenEvenAndOddFrequencyIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3445
