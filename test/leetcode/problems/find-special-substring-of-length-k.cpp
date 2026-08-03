#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-special-substring-of-length-k.h"

namespace leetcode::problem_3456 {

class FindSpecialSubstringOfLengthKTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindSpecialSubstringOfLengthKSolution solution_;
};

TEST_P(FindSpecialSubstringOfLengthKTest, Example1) {
  EXPECT_TRUE(solution_.hasSpecialSubstring("aaabaaa", 3));
}

TEST_P(FindSpecialSubstringOfLengthKTest, Example2) {
  EXPECT_FALSE(solution_.hasSpecialSubstring("abc", 2));
}

TEST_P(FindSpecialSubstringOfLengthKTest, SelfAuthored1) {
  EXPECT_FALSE(solution_.hasSpecialSubstring("aaa", 2));
}

TEST_P(FindSpecialSubstringOfLengthKTest, SelfAuthored2) {
  EXPECT_TRUE(solution_.hasSpecialSubstring("aabbaa", 2));
}

INSTANTIATE_TEST_SUITE_P(FireStrategy, FindSpecialSubstringOfLengthKTest,
                         ::testing::ValuesIn(
                             FindSpecialSubstringOfLengthKSolution().getStrategyNames()));

}  // namespace leetcode::problem_3456
