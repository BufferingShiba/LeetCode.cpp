#include <gtest/gtest.h>

#include "leetcode/problems/search-insert-position.h"

namespace leetcode {
namespace problem_35 {
namespace {

int CallSearchInsert(SearchInsertPositionSolution& solution, std::vector<int> nums,
                     int target) {
  return solution.searchInsert(nums, target);
}

}  // namespace

class SearchInsertPositionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SearchInsertPositionSolution solution;
};

TEST_P(SearchInsertPositionTest, Example1) {
  std::vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(CallSearchInsert(solution, nums, 5), 2);
}

TEST_P(SearchInsertPositionTest, Example2) {
  std::vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(CallSearchInsert(solution, nums, 2), 1);
}

TEST_P(SearchInsertPositionTest, Example3) {
  std::vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(CallSearchInsert(solution, nums, 7), 4);
}

TEST_P(SearchInsertPositionTest, SelfAuthoredTargetLessThanAll) {
  std::vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(CallSearchInsert(solution, nums, 0), 0);
}

TEST_P(SearchInsertPositionTest, SelfAuthoredSingleElementFound) {
  std::vector<int> nums{5};
  EXPECT_EQ(CallSearchInsert(solution, nums, 5), 0);
}

TEST_P(SearchInsertPositionTest, SelfAuthoredSingleElementInsertBefore) {
  std::vector<int> nums{5};
  EXPECT_EQ(CallSearchInsert(solution, nums, 3), 0);
}

INSTANTIATE_TEST_SUITE_P(
    SearchInsertPositionTestSuite, SearchInsertPositionTest,
    ::testing::ValuesIn(SearchInsertPositionSolution().getStrategyNames()));

}  // namespace problem_35
}  // namespace leetcode
