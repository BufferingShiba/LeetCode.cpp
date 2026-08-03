#include <gtest/gtest.h>

#include "leetcode/problems/maximize-subarrays-after-removing-one-conflicting-pair.h"

namespace leetcode {
namespace problem_3480 {

class MaximizeSubarraysAfterRemovingOneConflictingPairTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MaximizeSubarraysAfterRemovingOneConflictingPairSolution solution_;
};

TEST_P(MaximizeSubarraysAfterRemovingOneConflictingPairTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> conflictingPairs = {{2, 3}, {1, 4}};
  EXPECT_EQ(solution_.maxSubarrays(n, conflictingPairs), 9);
}

TEST_P(MaximizeSubarraysAfterRemovingOneConflictingPairTest, Example2) {
  int n = 5;
  std::vector<std::vector<int>> conflictingPairs = {
      {1, 2}, {2, 5}, {3, 5}};
  EXPECT_EQ(solution_.maxSubarrays(n, conflictingPairs), 12);
}

TEST_P(MaximizeSubarraysAfterRemovingOneConflictingPairTest, SelfAuthoredSinglePair) {
  int n = 3;
  std::vector<std::vector<int>> conflictingPairs = {{1, 3}};
  // Only one pair, must remove it. After removal all subarrays valid.
  // Total subarrays = 3*4/2 = 6.
  EXPECT_EQ(solution_.maxSubarrays(n, conflictingPairs), 6);
}

TEST_P(MaximizeSubarraysAfterRemovingOneConflictingPairTest, SelfAuthoredTiedMinimum) {
  int n = 3;
  std::vector<std::vector<int>> conflictingPairs = {{2, 3}, {1, 3}};
  // As analyzed: total valid with both = 4; best gain = 1 (remove [2,3])
  EXPECT_EQ(solution_.maxSubarrays(n, conflictingPairs), 5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximizeSubarraysAfterRemovingOneConflictingPairTest,
    ::testing::ValuesIn(
        MaximizeSubarraysAfterRemovingOneConflictingPairSolution()
            .getStrategyNames()));

}  // namespace problem_3480
}  // namespace leetcode
