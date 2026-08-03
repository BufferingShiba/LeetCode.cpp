#include "leetcode/problems/find-the-maximum-number-of-elements-in-subset.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3020 {

class FindTheMaximumNumberOfElementsInSubsetTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheMaximumNumberOfElementsInSubsetSolution solution;
};

TEST_P(FindTheMaximumNumberOfElementsInSubsetTest, Example1) {
  vector<int> nums{5, 4, 1, 2, 2};
  EXPECT_EQ(solution.maximumLength(nums), 3);
}

TEST_P(FindTheMaximumNumberOfElementsInSubsetTest, Example2) {
  vector<int> nums{1, 3, 2, 4};
  EXPECT_EQ(solution.maximumLength(nums), 1);
}

TEST_P(FindTheMaximumNumberOfElementsInSubsetTest, AllOnes) {
  vector<int> nums{1, 1, 1, 1, 1};
  EXPECT_EQ(solution.maximumLength(nums), 5);
}

TEST_P(FindTheMaximumNumberOfElementsInSubsetTest, ChainWithExtraCopy) {
  vector<int> nums{2, 4, 4, 2, 4};
  EXPECT_EQ(solution.maximumLength(nums), 3);
}

TEST_P(FindTheMaximumNumberOfElementsInSubsetTest, OneChainPlusTwoChain) {
  vector<int> nums{1, 1, 2, 4, 2};
  EXPECT_EQ(solution.maximumLength(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindTheMaximumNumberOfElementsInSubsetTest,
    ::testing::ValuesIn(FindTheMaximumNumberOfElementsInSubsetSolution().getStrategyNames()));

}  // namespace problem_3020
}  // namespace leetcode
