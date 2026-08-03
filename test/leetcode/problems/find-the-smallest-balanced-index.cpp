#include "leetcode/problems/find-the-smallest-balanced-index.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3862 {

class FindTheSmallestBalancedIndexTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheSmallestBalancedIndexSolution solution;
};

TEST_P(FindTheSmallestBalancedIndexTest, Example1) {
  std::vector<int> nums = {2, 1, 2};
  EXPECT_EQ(solution.smallestBalancedIndex(nums), 1);
}

TEST_P(FindTheSmallestBalancedIndexTest, Example2) {
  std::vector<int> nums = {2, 8, 2, 2, 5};
  EXPECT_EQ(solution.smallestBalancedIndex(nums), 2);
}

TEST_P(FindTheSmallestBalancedIndexTest, Example3) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.smallestBalancedIndex(nums), -1);
}

TEST_P(FindTheSmallestBalancedIndexTest, SelfAuthoredSingleElementOne) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.smallestBalancedIndex(nums), -1);
}

TEST_P(FindTheSmallestBalancedIndexTest, SelfAuthoredEmptyLeftEmptyRightZero) {
  std::vector<int> nums = {0, 0, 0};
  // left sum = 0 and right product = 0 for i=0 (right elements {0,0}).
  EXPECT_EQ(solution.smallestBalancedIndex(nums), 0);
}

TEST_P(FindTheSmallestBalancedIndexTest, SelfAuthoredLargeProduct) {
  std::vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
  EXPECT_EQ(solution.smallestBalancedIndex(nums), -1);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheSmallestBalancedIndexTestCases, FindTheSmallestBalancedIndexTest,
    ::testing::ValuesIn(FindTheSmallestBalancedIndexSolution().getStrategyNames()));

}  // namespace problem_3862
}  // namespace leetcode
