#include "leetcode/problems/lexicographically-smallest-string-after-operations-with-constraint.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3106 {

class LexicographicallySmallestStringAfterOperationsWithConstraintTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LexicographicallySmallestStringAfterOperationsWithConstraintSolution solution_;
};

TEST_P(LexicographicallySmallestStringAfterOperationsWithConstraintTest,
       Example1) {
  EXPECT_EQ("aaaz", solution_.getSmallestString("zbbz", 3));
}

TEST_P(LexicographicallySmallestStringAfterOperationsWithConstraintTest,
       Example2) {
  EXPECT_EQ("aawcd", solution_.getSmallestString("xaxcd", 4));
}

TEST_P(LexicographicallySmallestStringAfterOperationsWithConstraintTest,
       Example3) {
  EXPECT_EQ("lol", solution_.getSmallestString("lol", 0));
}

TEST_P(LexicographicallySmallestStringAfterOperationsWithConstraintTest,
       SelfAuthoredSingleCharNoBudget) {
  EXPECT_EQ("a", solution_.getSmallestString("a", 0));
}

TEST_P(LexicographicallySmallestStringAfterOperationsWithConstraintTest,
       SelfAuthoredWrapAroundToA) {
  EXPECT_EQ("aa", solution_.getSmallestString("zz", 2));
}

TEST_P(LexicographicallySmallestStringAfterOperationsWithConstraintTest,
       SelfAuthoredPartialBudget) {
  // "ba" with k=1: first char 'b' -> can reach 'a' (distance 1), then 'a' stays.
  EXPECT_EQ("aa", solution_.getSmallestString("ba", 1));
}

INSTANTIATE_TEST_SUITE_P(
    LexicographicallySmallestStringAfterOperationsWithConstraintTest,
    LexicographicallySmallestStringAfterOperationsWithConstraintTest,
    ::testing::ValuesIn(
        LexicographicallySmallestStringAfterOperationsWithConstraintSolution()
            .getStrategyNames()));

}  // namespace problem_3106
}  // namespace leetcode
