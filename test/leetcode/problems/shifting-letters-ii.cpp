#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shifting-letters-ii.h"

namespace leetcode {
namespace problem_2381 {

class ShiftingLettersIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ShiftingLettersIiSolution solution_;
};

TEST_P(ShiftingLettersIiTest, Example1) {
  std::string s = "abc";
  std::vector<std::vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
  EXPECT_EQ(solution_.shiftingLetters(s, shifts), "ace");
}

TEST_P(ShiftingLettersIiTest, Example2) {
  std::string s = "dztz";
  std::vector<std::vector<int>> shifts = {{0, 0, 0}, {1, 1, 1}};
  EXPECT_EQ(solution_.shiftingLetters(s, shifts), "catz");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ShiftingLettersIiTest,
    ::testing::ValuesIn(ShiftingLettersIiSolution().getStrategyNames()));

}  // namespace problem_2381
}  // namespace leetcode
