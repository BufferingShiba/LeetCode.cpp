#include <gtest/gtest.h>

#include "leetcode/problems/maximum-k-to-sort-a-permutation.h"

namespace leetcode {
namespace problem_3644 {
namespace {

class MaximumKToSortAPermutationTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumKToSortAPermutationSolution solution_;
};

TEST_P(MaximumKToSortAPermutationTest, Examples) {
  // Example 1
  {
    std::vector<int> nums = {0, 3, 2, 1};
    EXPECT_EQ(solution_.sortPermutation(nums), 1);
  }

  // Example 2
  {
    std::vector<int> nums = {0, 1, 3, 2};
    EXPECT_EQ(solution_.sortPermutation(nums), 2);
  }

  // Example 3
  {
    std::vector<int> nums = {3, 2, 1, 0};
    EXPECT_EQ(solution_.sortPermutation(nums), 0);
  }
}

TEST_P(MaximumKToSortAPermutationTest, AlreadySorted) {
  std::vector<int> nums = {0, 1, 2, 3, 4};
  EXPECT_EQ(solution_.sortPermutation(nums), 0);
}

TEST_P(MaximumKToSortAPermutationTest, SingleElement) {
  std::vector<int> nums = {0};
  EXPECT_EQ(solution_.sortPermutation(nums), 0);
}

TEST_P(MaximumKToSortAPermutationTest, SelfAuthoredAllMisplaced) {
  // All elements misplaced: [4,3,2,1,0] -> misplaced = {4,3,2,1,0}, AND = 0
  std::vector<int> nums = {4, 3, 2, 1, 0};
  EXPECT_EQ(solution_.sortPermutation(nums), 0);
}

TEST_P(MaximumKToSortAPermutationTest, SelfAuthoredPartialMisplacedHighAND) {
  // nums = [0, 1, 7, 3, 4, 5, 6, 2] -> misplaced = {7, 2}
  // 7 (111) & 2 (010) = 2 (010)
  std::vector<int> nums = {0, 1, 7, 3, 4, 5, 6, 2};
  EXPECT_EQ(solution_.sortPermutation(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumKToSortAPermutationTest,
    testing::ValuesIn(
        MaximumKToSortAPermutationSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3644
}  // namespace leetcode
