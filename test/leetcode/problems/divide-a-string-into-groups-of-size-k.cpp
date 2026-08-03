#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/divide-a-string-into-groups-of-size-k.h"

namespace leetcode::problem_2138 {

class DivideAStringIntoGroupsOfSizeKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DivideAStringIntoGroupsOfSizeKSolution solution_;
};

TEST_P(DivideAStringIntoGroupsOfSizeKTest, Example1) {
  std::vector<std::string> expected = {"abc", "def", "ghi"};
  EXPECT_EQ(solution_.divideString("abcdefghi", 3, 'x'), expected);
}

TEST_P(DivideAStringIntoGroupsOfSizeKTest, Example2) {
  std::vector<std::string> expected = {"abc", "def", "ghi", "jxx"};
  EXPECT_EQ(solution_.divideString("abcdefghij", 3, 'x'), expected);
}

TEST_P(DivideAStringIntoGroupsOfSizeKTest, SelfAuthoredExactMultiple) {
  std::vector<std::string> expected = {"ab", "cd", "ef"};
  EXPECT_EQ(solution_.divideString("abcdef", 2, 'z'), expected);
}

TEST_P(DivideAStringIntoGroupsOfSizeKTest, SelfAuthoredSingleGroupWithFill) {
  std::vector<std::string> expected = {"axx"};
  EXPECT_EQ(solution_.divideString("a", 3, 'x'), expected);
}

INSTANTIATE_TEST_SUITE_P(
    DivideAStringIntoGroupsOfSizeKTestCases,
    DivideAStringIntoGroupsOfSizeKTest,
    ::testing::ValuesIn(DivideAStringIntoGroupsOfSizeKSolution().getStrategyNames()));

}  // namespace leetcode::problem_2138
