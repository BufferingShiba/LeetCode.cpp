#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/find-all-duplicates-in-an-array.h"

namespace leetcode::problem_442 {
namespace {

class FindAllDuplicatesInAnArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindAllDuplicatesInAnArraySolution solution;
};

TEST_P(FindAllDuplicatesInAnArrayTest, Example1) {
  std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(solution.findDuplicates(nums), expected);
}

TEST_P(FindAllDuplicatesInAnArrayTest, Example2) {
  std::vector<int> nums = {1, 1, 2};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.findDuplicates(nums), expected);
}

TEST_P(FindAllDuplicatesInAnArrayTest, Example3) {
  std::vector<int> nums = {1};
  std::vector<int> expected = {};
  EXPECT_EQ(solution.findDuplicates(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    All,
    FindAllDuplicatesInAnArrayTest,
    testing::ValuesIn(
        FindAllDuplicatesInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_442
