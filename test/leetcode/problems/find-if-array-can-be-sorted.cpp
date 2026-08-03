#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-if-array-can-be-sorted.h"

namespace leetcode {
namespace problem_3011 {

class FindIfArrayCanBeSortedTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindIfArrayCanBeSortedSolution solution;
};

TEST_P(FindIfArrayCanBeSortedTest, Example1) {
  std::vector<int> nums = {8, 4, 2, 30, 15};
  EXPECT_TRUE(solution.canSortArray(nums));
}

TEST_P(FindIfArrayCanBeSortedTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_TRUE(solution.canSortArray(nums));
}

TEST_P(FindIfArrayCanBeSortedTest, Example3) {
  std::vector<int> nums = {3, 16, 8, 4, 2};
  EXPECT_FALSE(solution.canSortArray(nums));
}

TEST_P(FindIfArrayCanBeSortedTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  EXPECT_TRUE(solution.canSortArray(nums));
}

TEST_P(FindIfArrayCanBeSortedTest, SelfAuthoredAllSamePopcount) {
  // All powers of two: 1, 2, 4, 8 (each has popcount = 1)
  std::vector<int> nums = {8, 4, 2, 1};
  EXPECT_TRUE(solution.canSortArray(nums));
}

TEST_P(FindIfArrayCanBeSortedTest, SelfAuthoredAlternatingPopcounts) {
  // 1(pc=1), 3(pc=2), 2(pc=1), 7(pc=3) — segments: [1], [3], [2], [7]
  // Check: 1<=3 ok, 3<=2 false
  std::vector<int> nums = {1, 3, 2, 7};
  EXPECT_FALSE(solution.canSortArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    FindIfArrayCanBeSortedTest,
    testing::ValuesIn(FindIfArrayCanBeSortedSolution().getStrategyNames()));

}  // namespace problem_3011
}  // namespace leetcode
