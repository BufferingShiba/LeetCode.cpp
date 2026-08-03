#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-maximum-removals-from-source-string.h"

namespace leetcode::problem_3316 {

class FindMaximumRemovalsFromSourceStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindMaximumRemovalsFromSourceStringSolution solution_;
};

TEST_P(FindMaximumRemovalsFromSourceStringTest, Example1) {
  std::vector<int> target = {0, 1, 2};
  EXPECT_EQ(solution_.maxRemovals("abbaa", "aba", target), 1);
}

TEST_P(FindMaximumRemovalsFromSourceStringTest, Example2) {
  std::vector<int> target = {0, 3};
  EXPECT_EQ(solution_.maxRemovals("bcda", "d", target), 2);
}

TEST_P(FindMaximumRemovalsFromSourceStringTest, Example3) {
  std::vector<int> target = {0, 1, 2};
  EXPECT_EQ(solution_.maxRemovals("dda", "dda", target), 0);
}

TEST_P(FindMaximumRemovalsFromSourceStringTest, Example4) {
  std::vector<int> target = {0, 2, 3, 4};
  EXPECT_EQ(solution_.maxRemovals("yeyeykyded", "yeyyd", target), 2);
}

TEST_P(FindMaximumRemovalsFromSourceStringTest, EdgeCaseAllMustKeep) {
  // pattern 等于 source：任何字符移除都会破坏子序列性
  std::vector<int> t1 = {0};
  std::vector<int> t2 = {0, 1};
  EXPECT_EQ(solution_.maxRemovals("a", "a", t1), 0);
  EXPECT_EQ(solution_.maxRemovals("ab", "ab", t2), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FindMaximumRemovalsFromSourceStringTestSuite,
    FindMaximumRemovalsFromSourceStringTest,
    ::testing::ValuesIn(
        FindMaximumRemovalsFromSourceStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_3316
