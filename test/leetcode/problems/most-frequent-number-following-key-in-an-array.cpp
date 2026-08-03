#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/most-frequent-number-following-key-in-an-array.h"

namespace leetcode {
namespace problem_2190 {
namespace {

class MostFrequentNumberFollowingKeyInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MostFrequentNumberFollowingKeyInAnArraySolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MostFrequentNumberFollowingKeyInAnArrayTest, Example1) {
  std::vector<int> nums = {1, 100, 200, 1, 100};
  int key = 1;
  EXPECT_EQ(100, solution.mostFrequent(nums, key));
}

TEST_P(MostFrequentNumberFollowingKeyInAnArrayTest, Example2) {
  std::vector<int> nums = {2, 2, 2, 2, 3};
  int key = 2;
  EXPECT_EQ(2, solution.mostFrequent(nums, key));
}

INSTANTIATE_TEST_SUITE_P(
    MostFrequentNumberFollowingKeyInAnArrayTestSuite,
    MostFrequentNumberFollowingKeyInAnArrayTest,
    ::testing::ValuesIn(
        MostFrequentNumberFollowingKeyInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2190
}  // namespace leetcode
