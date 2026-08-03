#include <gtest/gtest.h>

#include "leetcode/problems/search-in-rotated-sorted-array-ii.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_81 {

class SearchInRotatedSortedArrayIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SearchInRotatedSortedArrayIiSolution solution_;
};

TEST_P(SearchInRotatedSortedArrayIiTest, Example1) {
  std::vector<int> nums{2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  EXPECT_TRUE(solution_.search(nums, target));
}

TEST_P(SearchInRotatedSortedArrayIiTest, Example2) {
  std::vector<int> nums{2, 5, 6, 0, 0, 1, 2};
  int target = 3;
  EXPECT_FALSE(solution_.search(nums, target));
}

TEST_P(SearchInRotatedSortedArrayIiTest, SelfAuthoredDuplicateBoundary) {
  // 经典重复导致无法二分裁剪的用例
  std::vector<int> nums{1, 0, 1, 1, 1};
  int target = 0;
  EXPECT_TRUE(solution_.search(nums, target));
}

TEST_P(SearchInRotatedSortedArrayIiTest, SelfAuthoredSingleElementHit) {
  std::vector<int> nums{1};
  EXPECT_TRUE(solution_.search(nums, 1));
}

TEST_P(SearchInRotatedSortedArrayIiTest, SelfAuthoredSingleElementMiss) {
  std::vector<int> nums{1};
  EXPECT_FALSE(solution_.search(nums, 2));
}

INSTANTIATE_TEST_SUITE_P(
    SearchInRotatedSortedArrayIiTestSuite, SearchInRotatedSortedArrayIiTest,
    ::testing::ValuesIn(SearchInRotatedSortedArrayIiSolution().getStrategyNames()));

}  // namespace problem_81
}  // namespace leetcode
