#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-strings-can-be-made-equal-with-operations-ii.h"

namespace leetcode::problem_2840 {
namespace {

class CheckIfStringsCanBeMadeEqualWithOperationsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfStringsCanBeMadeEqualWithOperationsIiSolution solution_;
};

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsIiTest, Example1) {
  EXPECT_TRUE(solution_.checkStrings("abcdba", "cabdab"));
}

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsIiTest, Example2) {
  EXPECT_FALSE(solution_.checkStrings("abe", "bea"));
}

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsIiTest, SelfAuthoredSingleCharSame) {
  EXPECT_TRUE(solution_.checkStrings("a", "a"));
}

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsIiTest, SelfAuthoredSingleCharDiff) {
  EXPECT_FALSE(solution_.checkStrings("a", "b"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfStringsCanBeMadeEqualWithOperationsIiTestInstance,
    CheckIfStringsCanBeMadeEqualWithOperationsIiTest,
    ::testing::ValuesIn(
        CheckIfStringsCanBeMadeEqualWithOperationsIiSolution().
            getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2840
