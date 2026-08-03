#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/long-pressed-name.h"

namespace leetcode {
namespace problem_925 {

using leetcode::problem_925::LongPressedNameSolution;

class LongPressedNameTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  LongPressedNameSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(LongPressedNameTest, Example1) {
  EXPECT_TRUE(solution.isLongPressedName("alex", "aaleex"));
}

TEST_P(LongPressedNameTest, Example2) {
  EXPECT_FALSE(solution.isLongPressedName("saeed", "ssaaedd"));
}

TEST_P(LongPressedNameTest, SingleCharacterName) {
  EXPECT_TRUE(solution.isLongPressedName("a", "aaaaa"));
}

TEST_P(LongPressedNameTest, ExtraCharacterNotInName) {
  EXPECT_FALSE(solution.isLongPressedName("alex", "aaleexa"));
}

INSTANTIATE_TEST_SUITE_P(
    LongPressedNameTestSuit, LongPressedNameTest,
    ::testing::ValuesIn(LongPressedNameSolution().getStrategyNames()));

}  // namespace problem_925
}  // namespace leetcode
