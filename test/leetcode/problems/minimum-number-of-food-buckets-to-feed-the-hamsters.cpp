#include "leetcode/problems/minimum-number-of-food-buckets-to-feed-the-hamsters.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2086 {

class MinimumNumberOfFoodBucketsToFeedTheHamstersTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfFoodBucketsToFeedTheHamstersSolution solution;
};

TEST_P(MinimumNumberOfFoodBucketsToFeedTheHamstersTest, Example1) {
  EXPECT_EQ(solution.minimumBuckets("H..H"), 2);
}

TEST_P(MinimumNumberOfFoodBucketsToFeedTheHamstersTest, Example2) {
  EXPECT_EQ(solution.minimumBuckets(".H.H."), 1);
}

TEST_P(MinimumNumberOfFoodBucketsToFeedTheHamstersTest, Example3) {
  EXPECT_EQ(solution.minimumBuckets(".HHH."), -1);
}

TEST_P(MinimumNumberOfFoodBucketsToFeedTheHamstersTest, SingleHamsterMiddle) {
  EXPECT_EQ(solution.minimumBuckets(".H."), 1);
}

TEST_P(MinimumNumberOfFoodBucketsToFeedTheHamstersTest, SingleIsolatedHamster) {
  EXPECT_EQ(solution.minimumBuckets("H"), -1);
}

TEST_P(MinimumNumberOfFoodBucketsToFeedTheHamstersTest, SingleFedAtLeft) {
  EXPECT_EQ(solution.minimumBuckets(".H"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumNumberOfFoodBucketsToFeedTheHamstersTest,
    ::testing::ValuesIn(MinimumNumberOfFoodBucketsToFeedTheHamstersSolution().getStrategyNames()));

}  // namespace problem_2086
}  // namespace leetcode
