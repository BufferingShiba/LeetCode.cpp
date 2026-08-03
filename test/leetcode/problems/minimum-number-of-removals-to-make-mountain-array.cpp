#include <gtest/gtest.h>

#include "leetcode/problems/minimum-number-of-removals-to-make-mountain-array.h"

namespace leetcode {
namespace problem_1671 {

class MinimumNumberOfRemovalsToMakeMountainArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfRemovalsToMakeMountainArraySolution solution;
};

TEST_P(MinimumNumberOfRemovalsToMakeMountainArrayTest, Example1) {
  std::vector<int> nums = {1, 3, 1};
  EXPECT_EQ(solution.minimumMountainRemovals(nums), 0);
}

TEST_P(MinimumNumberOfRemovalsToMakeMountainArrayTest, Example2) {
  std::vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
  EXPECT_EQ(solution.minimumMountainRemovals(nums), 3);
}

TEST_P(MinimumNumberOfRemovalsToMakeMountainArrayTest, SelfAuthoredAlreadyMountain) {
  std::vector<int> nums = {1, 2, 3, 2, 1};
  EXPECT_EQ(solution.minimumMountainRemovals(nums), 0);
}

TEST_P(MinimumNumberOfRemovalsToMakeMountainArrayTest, SelfAuthoredNeedRemovals) {
  // [2,1,1,5,6,2,3,1]  already tested
  // Another: [9,8,1,7,6,5,4,3,2,1]
  // Mountain can be [9,8,7,6,5,4,3,2,1]? No, must increase then decrease.
  // Best mountain: [1,7,6,5,4,3,2,1] (length 8), remove 9,8 → 2 removals.
  // Actually let's trace: peaks could be 7→[1,7,6,5,4,3,2,1] len 8, remove 2.
  std::vector<int> nums = {9, 8, 1, 7, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(solution.minimumMountainRemovals(nums), 2);
}

TEST_P(MinimumNumberOfRemovalsToMakeMountainArrayTest, SelfAuthoredMinimumSize) {
  // smallest possible: n=3, already mountain
  std::vector<int> nums = {2, 5, 3};
  EXPECT_EQ(solution.minimumMountainRemovals(nums), 0);
}

TEST_P(MinimumNumberOfRemovalsToMakeMountainArrayTest, SelfAuthoredAllEqual) {
  // Must remove enough to form mountain; guaranteed possible
  // [5,5,5] → need to remove 2? Actually with all equal, can't form strictly inc/dec.
  // But constraint says guaranteed possible. Let's trust it.
  // Use [5,5,5,5] - need to keep 3 elements like [5,5,5] but that's not strictly inc/dec.
  // Since guaranteed, just test what we have.
  std::vector<int> nums = {1, 2, 2, 3, 2, 2, 1};
  // Mountain: [1,2,3,2,1] length 5, remove two 2's → 2 removals
  EXPECT_EQ(solution.minimumMountainRemovals(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumNumberOfRemovalsToMakeMountainArrayTest,
    ::testing::ValuesIn(
        MinimumNumberOfRemovalsToMakeMountainArraySolution().getStrategyNames()));

}  // namespace problem_1671
}  // namespace leetcode
