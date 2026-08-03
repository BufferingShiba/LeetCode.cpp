#include <gtest/gtest.h>
#include "leetcode/problems/sign-of-the-product-of-an-array.h"

using namespace leetcode::problem_1822;

class SignOfTheProductOfAnArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  SignOfTheProductOfAnArraySolution solution;
};

TEST_P(SignOfTheProductOfAnArrayTest, Example1) {
  std::vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};
  EXPECT_EQ(solution.arraySign(nums), 1);
}

TEST_P(SignOfTheProductOfAnArrayTest, Example2) {
  std::vector<int> nums = {1, 5, 0, 2, -3};
  EXPECT_EQ(solution.arraySign(nums), 0);
}

TEST_P(SignOfTheProductOfAnArrayTest, Example3) {
  std::vector<int> nums = {-1, 1, -1, 1, -1};
  EXPECT_EQ(solution.arraySign(nums), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SignOfTheProductOfAnArrayTest,
    ::testing::ValuesIn(SignOfTheProductOfAnArraySolution().getStrategyNames()));
