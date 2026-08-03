#include "leetcode/problems/count-the-number-of-incremovable-subarrays-ii.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2972 {
namespace {

using CountTheNumberOfIncremovableSubarraysIiTest =
    ::testing::TestWithParam<std::string>;

}  // namespace

TEST_P(CountTheNumberOfIncremovableSubarraysIiTest, Examples) {
  CountTheNumberOfIncremovableSubarraysIiSolution solution;
  solution.setStrategy(GetParam());

  {
    std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(10, solution.incremovableSubarrayCount(nums));
  }
  {
    std::vector<int> nums = {6, 5, 7, 8};
    EXPECT_EQ(7, solution.incremovableSubarrayCount(nums));
  }
  {
    std::vector<int> nums = {8, 7, 6, 6};
    EXPECT_EQ(3, solution.incremovableSubarrayCount(nums));
  }
}

TEST_P(CountTheNumberOfIncremovableSubarraysIiTest, EdgeCases) {
  CountTheNumberOfIncremovableSubarraysIiSolution solution;
  solution.setStrategy(GetParam());

  {
    // Single element: only the whole subarray works.
    std::vector<int> nums = {1};
    EXPECT_EQ(1, solution.incremovableSubarrayCount(nums));
  }
  {
    // Two equal elements -> removing [1,1] gives [5] ok; removing [0,0] gives
    // [5]; removing [0,1] gives []. All three valid.
    std::vector<int> nums = {5, 5};
    EXPECT_EQ(3, solution.incremovableSubarrayCount(nums));
  }
  {
    // Descending array of length 3: removals that leave a single element or
    // empty are valid.
    std::vector<int> nums = {3, 2, 1};
    // [2,2]->[3,2] not inc; [1,1]->[3,1] no; [0,0]->[2,1] no; [0,1]->[1] ok;
    // [1,2]->[3] ok; [0,2]->[] ok. Also single-longer? all length-2 and len-3
    // partially. Count: [0,1],[1,2],[0,2] = 3.
    EXPECT_EQ(3, solution.incremovableSubarrayCount(nums));
  }
}

TEST_P(CountTheNumberOfIncremovableSubarraysIiTest, MultiPeak) {
  CountTheNumberOfIncremovableSubarraysIiSolution solution;
  solution.setStrategy(GetParam());

  {
    // [1,3,2]: all incremovable subarrays from manual enumeration = 5.
    std::vector<int> nums = {1, 3, 2};
    EXPECT_EQ(5, solution.incremovableSubarrayCount(nums));
  }
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfIncremovableSubarraysIiTestSuite,
    CountTheNumberOfIncremovableSubarraysIiTest,
    ::testing::ValuesIn(
        CountTheNumberOfIncremovableSubarraysIiSolution()
            .getStrategyNames()));

}  // namespace problem_2972
}  // namespace leetcode
