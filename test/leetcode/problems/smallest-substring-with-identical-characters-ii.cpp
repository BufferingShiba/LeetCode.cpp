#include <string>

#include <gtest/gtest.h>

#include "leetcode/problems/smallest-substring-with-identical-characters-ii.h"

namespace leetcode {
namespace problem_3399 {
namespace {

class SmallestSubstringWithIdenticalCharactersIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  SmallestSubstringWithIdenticalCharactersIiSolution solution_;
};

TEST_P(SmallestSubstringWithIdenticalCharactersIiTest, Example1) {
  EXPECT_EQ(2, solution_.minLength("000001", 1));
}

TEST_P(SmallestSubstringWithIdenticalCharactersIiTest, Example2) {
  EXPECT_EQ(1, solution_.minLength("0000", 2));
}

TEST_P(SmallestSubstringWithIdenticalCharactersIiTest, Example3) {
  EXPECT_EQ(1, solution_.minLength("0101", 0));
}

TEST_P(SmallestSubstringWithIdenticalCharactersIiTest,
       SelfAuthoredBoundaryMergeAtLimitOne) {
  EXPECT_EQ(2, solution_.minLength("0110", 1));
}

TEST_P(SmallestSubstringWithIdenticalCharactersIiTest,
       SelfAuthoredAlreadyAlternating) {
  EXPECT_EQ(1, solution_.minLength("101010", 0));
}

INSTANTIATE_TEST_SUITE_P(
    SmallestSubstringWithIdenticalCharactersIiTestSuite,
    SmallestSubstringWithIdenticalCharactersIiTest,
    ::testing::ValuesIn(
        SmallestSubstringWithIdenticalCharactersIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3399
}  // namespace leetcode
