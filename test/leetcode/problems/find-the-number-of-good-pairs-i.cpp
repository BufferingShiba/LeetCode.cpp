#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-number-of-good-pairs-i.h"

namespace leetcode {
namespace problem_3162 {
namespace {

class FindTheNumberOfGoodPairsITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheNumberOfGoodPairsISolution solution;
};

TEST_P(FindTheNumberOfGoodPairsITest, Example1) {
  std::vector<int> nums1 = {1, 3, 4};
  std::vector<int> nums2 = {1, 3, 4};
  int k = 1;
  EXPECT_EQ(solution.numberOfPairs(nums1, nums2, k), 5);
}

TEST_P(FindTheNumberOfGoodPairsITest, Example2) {
  std::vector<int> nums1 = {1, 2, 4, 12};
  std::vector<int> nums2 = {2, 4};
  int k = 3;
  EXPECT_EQ(solution.numberOfPairs(nums1, nums2, k), 2);
}

TEST_P(FindTheNumberOfGoodPairsITest, SelfAuthoredNoGoodPair) {
  std::vector<int> nums1 = {1};
  std::vector<int> nums2 = {2};
  int k = 3;
  EXPECT_EQ(solution.numberOfPairs(nums1, nums2, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheNumberOfGoodPairsITestParameters, FindTheNumberOfGoodPairsITest,
    ::testing::ValuesIn(FindTheNumberOfGoodPairsISolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3162
}  // namespace leetcode
