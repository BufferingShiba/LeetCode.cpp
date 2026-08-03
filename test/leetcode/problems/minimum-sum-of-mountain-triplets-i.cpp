#include <gtest/gtest.h>

#include "leetcode/problems/minimum-sum-of-mountain-triplets-i.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2908 {
namespace test {

class MinimumSumOfMountainTripletsITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSumOfMountainTripletsISolution solution;
};

TEST_P(MinimumSumOfMountainTripletsITest, Example1) {
  std::vector<int> nums = {8, 6, 1, 5, 3};
  EXPECT_EQ(9, solution.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsITest, Example2) {
  std::vector<int> nums = {5, 4, 8, 7, 10, 2};
  EXPECT_EQ(13, solution.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsITest, Example3) {
  std::vector<int> nums = {6, 5, 4, 3, 4, 5};
  EXPECT_EQ(-1, solution.minimumSum(nums));
}

TEST_P(MinimumSumOfMountainTripletsITest, SelfAuthoredMinimumLengthAllEqual) {
  std::vector<int> nums = {5, 5, 5};
  EXPECT_EQ(-1, solution.minimumSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSumOfMountainTripletsITestInstance, MinimumSumOfMountainTripletsITest,
    ::testing::ValuesIn(MinimumSumOfMountainTripletsISolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_2908
}  // namespace leetcode
