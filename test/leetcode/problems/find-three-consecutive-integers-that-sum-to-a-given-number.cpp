#include <gtest/gtest.h>
#include "leetcode/problems/find-three-consecutive-integers-that-sum-to-a-given-number.h"

namespace leetcode {
namespace problem_2177 {

class FindThreeConsecutiveIntegersThatSumToAGivenNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution solution;
};

TEST_P(FindThreeConsecutiveIntegersThatSumToAGivenNumberTest, Example1) {
  long long num = 33;
  std::vector<long long> expected = {10, 11, 12};
  EXPECT_EQ(solution.sumOfThree(num), expected);
}

TEST_P(FindThreeConsecutiveIntegersThatSumToAGivenNumberTest, Example2) {
  long long num = 4;
  std::vector<long long> expected = {};
  EXPECT_EQ(solution.sumOfThree(num), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindThreeConsecutiveIntegersThatSumToAGivenNumberTest,
    ::testing::ValuesIn(FindThreeConsecutiveIntegersThatSumToAGivenNumberSolution().getStrategyNames()));

}  // namespace problem_2177
}  // namespace leetcode
