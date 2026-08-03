#include <gtest/gtest.h>

#include "leetcode/problems/find-the-xor-of-numbers-which-appear-twice.h"

namespace leetcode {
namespace problem_3158 {

class FindTheXorOfNumbersWhichAppearTwiceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  FindTheXorOfNumbersWhichAppearTwiceSolution solution;
};

TEST_P(FindTheXorOfNumbersWhichAppearTwiceTest, Example1) {
  std::vector<int> nums = {1, 2, 1, 3};
  EXPECT_EQ(solution.duplicateNumbersXOR(nums), 1);
}

TEST_P(FindTheXorOfNumbersWhichAppearTwiceTest, Example2) {
  std::vector<int> nums = {1, 2, 3};
  EXPECT_EQ(solution.duplicateNumbersXOR(nums), 0);
}

TEST_P(FindTheXorOfNumbersWhichAppearTwiceTest, Example3) {
  std::vector<int> nums = {1, 2, 2, 1};
  EXPECT_EQ(solution.duplicateNumbersXOR(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheXorOfNumbersWhichAppearTwiceTest,
    ::testing::ValuesIn(FindTheXorOfNumbersWhichAppearTwiceSolution().getStrategyNames()));

}  // namespace problem_3158
}  // namespace leetcode
