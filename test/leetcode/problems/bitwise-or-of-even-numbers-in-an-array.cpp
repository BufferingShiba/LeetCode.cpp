#include <gtest/gtest.h>
#include "leetcode/problems/bitwise-or-of-even-numbers-in-an-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3688 {

class BitwiseOrOfEvenNumbersInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  BitwiseOrOfEvenNumbersInAnArraySolution solution;
};

TEST_P(BitwiseOrOfEvenNumbersInAnArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(6, solution.evenNumberBitwiseORs(nums));
}

TEST_P(BitwiseOrOfEvenNumbersInAnArrayTest, Example2) {
  std::vector<int> nums = {7, 9, 11};
  EXPECT_EQ(0, solution.evenNumberBitwiseORs(nums));
}

TEST_P(BitwiseOrOfEvenNumbersInAnArrayTest, Example3) {
  std::vector<int> nums = {1, 8, 16};
  EXPECT_EQ(24, solution.evenNumberBitwiseORs(nums));
}

TEST_P(BitwiseOrOfEvenNumbersInAnArrayTest, SelfAuthoredAllEven) {
  std::vector<int> nums = {2, 4, 8};
  EXPECT_EQ(14, solution.evenNumberBitwiseORs(nums));
}

TEST_P(BitwiseOrOfEvenNumbersInAnArrayTest, SelfAuthoredAllOdd) {
  std::vector<int> nums = {3, 5, 7};
  EXPECT_EQ(0, solution.evenNumberBitwiseORs(nums));
}

INSTANTIATE_TEST_SUITE_P(
    BitwiseOrOfEvenNumbersInAnArrayTestSuite,
    BitwiseOrOfEvenNumbersInAnArrayTest,
    ::testing::ValuesIn(
        BitwiseOrOfEvenNumbersInAnArraySolution().getStrategyNames()));

}  // namespace problem_3688
}  // namespace leetcode
