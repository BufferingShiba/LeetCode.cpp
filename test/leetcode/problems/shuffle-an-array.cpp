#include "leetcode/problems/shuffle-an-array.h"

#include "gtest/gtest.h"

#include <algorithm>

namespace leetcode {
namespace problem_384 {

TEST(LeetCode, SolutionTest) {
  std::vector<int> nums = {1, 2, 3};
  Solution obj(nums);

  // reset() returns the original configuration.
  EXPECT_EQ(std::vector<int>({1, 2, 3}), obj.reset());

  // shuffle() returns a permutation of the original array
  // (same multiset, some ordering), and is deterministic in content.
  std::vector<int> shuffled = obj.shuffle();
  std::vector<int> sorted = shuffled;
  std::sort(sorted.begin(), sorted.end());
  EXPECT_EQ(std::vector<int>({1, 2, 3}), sorted);

  // reset() again after shuffling restores the original array.
  EXPECT_EQ(std::vector<int>({1, 2, 3}), obj.reset());
}

}  // namespace problem_384
}  // namespace leetcode
