#include "leetcode/problems/most-frequent-ids.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3092 {

class MostFrequentIdsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MostFrequentIdsSolution solution;
};

TEST_P(MostFrequentIdsTest, Example1) {
  std::vector<int> nums = {2, 3, 2, 1};
  std::vector<int> freq = {3, 2, -3, 1};
  std::vector<long long> expected = {3, 3, 2, 2};
  EXPECT_EQ(solution.mostFrequentIDs(nums, freq), expected);
}

TEST_P(MostFrequentIdsTest, Example2) {
  std::vector<int> nums = {5, 5, 3};
  std::vector<int> freq = {2, -2, 1};
  std::vector<long long> expected = {2, 0, 1};
  EXPECT_EQ(solution.mostFrequentIDs(nums, freq), expected);
}

TEST_P(MostFrequentIdsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {1};
  std::vector<int> freq = {7};
  std::vector<long long> expected = {7};
  EXPECT_EQ(solution.mostFrequentIDs(nums, freq), expected);
}

TEST_P(MostFrequentIdsTest, SelfAuthoredFrequenciesTie) {
  // Two IDs each reach count 2; maintain order is irrelevant, max count = 2.
  std::vector<int> nums = {1, 2, 1, 2};
  std::vector<int> freq = {2, 2, -1, 1};
  // After step0: cnt1=2 -> max=2
  // After step1: cnt1=2,cnt2=2 -> max=2
  // After step2: cnt1=1,cnt2=2 -> max=2
  // After step3: cnt1=1,cnt2=3 -> max=3
  std::vector<long long> expected = {2, 2, 2, 3};
  EXPECT_EQ(solution.mostFrequentIDs(nums, freq), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MostFrequentIdsTestCases, MostFrequentIdsTest,
    ::testing::ValuesIn(MostFrequentIdsSolution().getStrategyNames()));

}  // namespace problem_3092
}  // namespace leetcode
