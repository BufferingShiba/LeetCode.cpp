#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/smallest-index-with-digit-sum-equal-to-index.h"

namespace leetcode::problem_3550 {

class SmallestIndexWithDigitSumEqualToIndexTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SmallestIndexWithDigitSumEqualToIndexSolution solution_;
};

TEST_P(SmallestIndexWithDigitSumEqualToIndexTest, Example1) {
  std::vector<int> nums{1, 3, 2};
  EXPECT_EQ(solution_.smallestIndex(nums), 2);
}

TEST_P(SmallestIndexWithDigitSumEqualToIndexTest, Example2) {
  std::vector<int> nums{1, 10, 11};
  EXPECT_EQ(solution_.smallestIndex(nums), 1);
}

TEST_P(SmallestIndexWithDigitSumEqualToIndexTest, Example3) {
  std::vector<int> nums{1, 2, 3};
  EXPECT_EQ(solution_.smallestIndex(nums), -1);
}

TEST_P(SmallestIndexWithDigitSumEqualToIndexTest, ZeroAtZeroIndex) {
  std::vector<int> nums{0, 10, 20};
  EXPECT_EQ(solution_.smallestIndex(nums), 0);
}

TEST_P(SmallestIndexWithDigitSumEqualToIndexTest, IndexTwoMatches) {
  std::vector<int> nums{100, 200, 11};
  EXPECT_EQ(solution_.smallestIndex(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestIndexWithDigitSumEqualToIndexTestSuite,
    SmallestIndexWithDigitSumEqualToIndexTest,
    ::testing::ValuesIn(
        SmallestIndexWithDigitSumEqualToIndexSolution().getStrategyNames()));

}  // namespace leetcode::problem_3550
