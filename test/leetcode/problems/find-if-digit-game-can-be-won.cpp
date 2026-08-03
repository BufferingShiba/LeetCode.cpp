#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-if-digit-game-can-be-won.h"

namespace leetcode {
namespace problem_3232 {
namespace {

class FindIfDigitGameCanBeWonTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindIfDigitGameCanBeWonSolution solution;
};

TEST_P(FindIfDigitGameCanBeWonTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 10};
  EXPECT_FALSE(solution.canAliceWin(nums));
}

TEST_P(FindIfDigitGameCanBeWonTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 14};
  EXPECT_TRUE(solution.canAliceWin(nums));
}

TEST_P(FindIfDigitGameCanBeWonTest, Example3) {
  std::vector<int> nums = {5, 5, 5, 25};
  EXPECT_TRUE(solution.canAliceWin(nums));
}

TEST_P(FindIfDigitGameCanBeWonTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {10};
  EXPECT_TRUE(solution.canAliceWin(nums));
}

TEST_P(FindIfDigitGameCanBeWonTest, SelfAuthoredAllDoubleDigits) {
  std::vector<int> nums = {11, 12, 13};
  EXPECT_TRUE(solution.canAliceWin(nums));
}

INSTANTIATE_TEST_SUITE_P(
    FindIfDigitGameCanBeWonTestSuite, FindIfDigitGameCanBeWonTest,
    ::testing::ValuesIn(FindIfDigitGameCanBeWonSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3232
}  // namespace leetcode
