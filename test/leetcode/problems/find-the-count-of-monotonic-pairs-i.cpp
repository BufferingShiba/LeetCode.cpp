#include <gtest/gtest.h>

#include "leetcode/problems/find-the-count-of-monotonic-pairs-i.h"

namespace leetcode {
namespace problem_3250 {

class FindTheCountOfMonotonicPairsITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheCountOfMonotonicPairsISolution solution_;
};

TEST_P(FindTheCountOfMonotonicPairsITest, Example1) {
  std::vector<int> nums = {2, 3, 2};
  EXPECT_EQ(solution_.countOfPairs(nums), 4);
}

TEST_P(FindTheCountOfMonotonicPairsITest, Example2) {
  std::vector<int> nums = {5, 5, 5, 5};
  EXPECT_EQ(solution_.countOfPairs(nums), 126);
}

TEST_P(FindTheCountOfMonotonicPairsITest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  // arr1[0] can be 0..7, arr2[0] = nums[0] - arr1[0]
  // So 8 possibilities.
  EXPECT_EQ(solution_.countOfPairs(nums), 8);
}

TEST_P(FindTheCountOfMonotonicPairsITest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> nums = {1, 3};
  // d = 2, arr1[0] in [0,1], arr1[1] >= arr1[0] + 2
  // arr1[0]=0: arr1[1] in [2,3] → 2
  // arr1[0]=1: arr1[1] in [3,3] → 1
  // Total = 3
  EXPECT_EQ(solution_.countOfPairs(nums), 3);
}

TEST_P(FindTheCountOfMonotonicPairsITest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> nums = {3, 1};
  // d = max(0, 1-3) = 0
  // arr1 non-decreasing, arr2 non-increasing
  // Enumerate: (0,0), (0,1), (1,1) → 3
  EXPECT_EQ(solution_.countOfPairs(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheCountOfMonotonicPairsITest,
    testing::ValuesIn(
        FindTheCountOfMonotonicPairsISolution().getStrategyNames()));

}  // namespace problem_3250
}  // namespace leetcode
