#include <gtest/gtest.h>

#include "leetcode/problems/number-of-beautiful-pairs.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2748 {
namespace {

class NumberOfBeautifulPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfBeautifulPairsSolution solution;
};

TEST_P(NumberOfBeautifulPairsTest, Example1) {
  std::vector<int> nums = {2, 5, 1, 4};
  EXPECT_EQ(solution.countBeautifulPairs(nums), 5);
}

TEST_P(NumberOfBeautifulPairsTest, Example2) {
  std::vector<int> nums = {11, 21, 12};
  EXPECT_EQ(solution.countBeautifulPairs(nums), 2);
}

TEST_P(NumberOfBeautifulPairsTest, SelfAuthoredSingleDigitAllCoprime) {
  std::vector<int> nums = {2, 3, 5, 7};
  int expected = 0;
  for (std::size_t i = 0; i < nums.size(); ++i) {
    for (std::size_t j = i + 1; j < nums.size(); ++j) {
      if (std::gcd(nums[i], nums[j]) == 1) ++expected;
    }
  }
  EXPECT_EQ(solution.countBeautifulPairs(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfBeautifulPairsTestSuite, NumberOfBeautifulPairsTest,
    ::testing::ValuesIn(NumberOfBeautifulPairsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2748
}  // namespace leetcode
