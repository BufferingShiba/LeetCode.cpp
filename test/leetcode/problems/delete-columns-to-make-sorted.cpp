#include "leetcode/problems/delete-columns-to-make-sorted.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_944 {

class DeleteColumnsToMakeSortedTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DeleteColumnsToMakeSortedSolution solution;
};

TEST_P(DeleteColumnsToMakeSortedTest, Example1) {
  vector<string> strs = {"cba", "daf", "ghi"};
  int expected = 1;
  int result = solution.minDeletionSize(strs);
  EXPECT_EQ(expected, result);
}

TEST_P(DeleteColumnsToMakeSortedTest, Example2) {
  vector<string> strs = {"a", "b"};
  int expected = 0;
  int result = solution.minDeletionSize(strs);
  EXPECT_EQ(expected, result);
}

TEST_P(DeleteColumnsToMakeSortedTest, Example3) {
  vector<string> strs = {"zyx", "wvu", "tsr"};
  int expected = 3;
  int result = solution.minDeletionSize(strs);
  EXPECT_EQ(expected, result);
}

TEST_P(DeleteColumnsToMakeSortedTest, AllColumnsSorted) {
  vector<string> strs = {"abc", "def", "ghi"};
  int expected = 0;
  int result = solution.minDeletionSize(strs);
  EXPECT_EQ(expected, result);
}

TEST_P(DeleteColumnsToMakeSortedTest, SingleRow) {
  vector<string> strs = {"abcdef"};
  int expected = 0;
  int result = solution.minDeletionSize(strs);
  EXPECT_EQ(expected, result);
}

TEST_P(DeleteColumnsToMakeSortedTest, AllColumnsUnsorted) {
  vector<string> strs = {"cba", "azy", "yxw"};
  int expected = 3;
  int result = solution.minDeletionSize(strs);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, DeleteColumnsToMakeSortedTest,
    ::testing::ValuesIn(DeleteColumnsToMakeSortedSolution().getStrategyNames()));

}  // namespace problem_944
}  // namespace leetcode