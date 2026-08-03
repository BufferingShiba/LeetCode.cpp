#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/number-of-arithmetic-triplets.h"

namespace leetcode::problem_2367 {

class NumberOfArithmeticTripletsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfArithmeticTripletsSolution solution;
};

TEST_P(NumberOfArithmeticTripletsTest, Example1) {
  std::vector<int> nums{0, 1, 4, 6, 7, 10};
  int diff = 3;
  EXPECT_EQ(solution.arithmeticTriplets(nums, diff), 2);
}

TEST_P(NumberOfArithmeticTripletsTest, Example2) {
  std::vector<int> nums{4, 5, 6, 7, 8, 9};
  int diff = 2;
  EXPECT_EQ(solution.arithmeticTriplets(nums, diff), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfArithmeticTripletsTests,
    NumberOfArithmeticTripletsTest,
    ::testing::ValuesIn(NumberOfArithmeticTripletsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2367
