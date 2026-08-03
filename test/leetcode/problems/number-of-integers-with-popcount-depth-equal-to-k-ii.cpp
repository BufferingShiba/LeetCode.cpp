#include <gtest/gtest.h>

#include "leetcode/problems/number-of-integers-with-popcount-depth-equal-to-k-ii.h"

namespace leetcode {
namespace problem_3624 {

class NumberOfIntegersWithPopcountDepthEqualToKIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  NumberOfIntegersWithPopcountDepthEqualToKIiSolution solution;
};

TEST_P(NumberOfIntegersWithPopcountDepthEqualToKIiTest, Example1) {
  std::vector<long long> nums = {2, 4};
  std::vector<std::vector<long long>> queries = {
      {1, 0, 1, 1}, {2, 1, 1}, {1, 0, 1, 0}};
  std::vector<int> expected = {2, 1};
  EXPECT_EQ(solution.popcountDepth(nums, queries), expected);
}

TEST_P(NumberOfIntegersWithPopcountDepthEqualToKIiTest, Example2) {
  std::vector<long long> nums = {3, 5, 6};
  std::vector<std::vector<long long>> queries = {
      {1, 0, 2, 2}, {2, 1, 4}, {1, 1, 2, 1}, {1, 0, 1, 0}};
  std::vector<int> expected = {3, 1, 0};
  EXPECT_EQ(solution.popcountDepth(nums, queries), expected);
}

TEST_P(NumberOfIntegersWithPopcountDepthEqualToKIiTest, Example3) {
  std::vector<long long> nums = {1, 2};
  std::vector<std::vector<long long>> queries = {
      {1, 0, 1, 1}, {2, 0, 3}, {1, 0, 0, 1}, {1, 0, 0, 2}};
  std::vector<int> expected = {1, 0, 1};
  EXPECT_EQ(solution.popcountDepth(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfIntegersWithPopcountDepthEqualToKIiTestSuite,
    NumberOfIntegersWithPopcountDepthEqualToKIiTest,
    ::testing::ValuesIn(NumberOfIntegersWithPopcountDepthEqualToKIiSolution()
                            .getStrategyNames()));

}  // namespace problem_3624
}  // namespace leetcode
