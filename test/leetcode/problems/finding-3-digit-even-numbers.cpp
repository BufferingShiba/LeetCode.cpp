#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/finding-3-digit-even-numbers.h"

namespace leetcode::problem_2094 {

class Finding3DigitEvenNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  Finding3DigitEvenNumbersSolution solution;
};

TEST_P(Finding3DigitEvenNumbersTest, Example1) {
  std::vector<int> digits{2, 1, 3, 0};
  std::vector<int> expected{102, 120, 130, 132, 210, 230, 302, 310, 312, 320};
  EXPECT_EQ(solution.findEvenNumbers(digits), expected);
}

TEST_P(Finding3DigitEvenNumbersTest, Example2) {
  std::vector<int> digits{2, 2, 8, 8, 2};
  std::vector<int> expected{222, 228, 282, 288, 822, 828, 882};
  EXPECT_EQ(solution.findEvenNumbers(digits), expected);
}

TEST_P(Finding3DigitEvenNumbersTest, Example3) {
  std::vector<int> digits{3, 7, 5};
  std::vector<int> expected{};
  EXPECT_EQ(solution.findEvenNumbers(digits), expected);
}

TEST_P(Finding3DigitEvenNumbersTest, SelfAuthoredAllSameDigit) {
  std::vector<int> digits{0, 0, 2};
  std::vector<int> expected{200};
  EXPECT_EQ(solution.findEvenNumbers(digits), expected);
}

TEST_P(Finding3DigitEvenNumbersTest, Includes100) {
  std::vector<int> digits{1, 0, 0};
  std::vector<int> expected{100};
  EXPECT_EQ(solution.findEvenNumbers(digits), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Finding3DigitEvenNumbersTestSuite, Finding3DigitEvenNumbersTest,
    ::testing::ValuesIn(Finding3DigitEvenNumbersSolution().getStrategyNames()));

}  // namespace leetcode::problem_2094
