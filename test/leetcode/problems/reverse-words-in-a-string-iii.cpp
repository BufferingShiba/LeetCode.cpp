#include <gtest/gtest.h>

#include "leetcode/problems/reverse-words-in-a-string-iii.h"

namespace leetcode::problem_557 {

class ReverseWordsInAStringIiiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReverseWordsInAStringIiiSolution solution_;
};

TEST_P(ReverseWordsInAStringIiiTest, OfficialExamples) {
  EXPECT_EQ(solution_.reverseWords("Let's take LeetCode contest"),
            "s'teL ekat edoCteeL tsetnoc");
  EXPECT_EQ(solution_.reverseWords("Mr Ding"), "rM gniD");
}

TEST_P(ReverseWordsInAStringIiiTest, SelfAuthored) {
  EXPECT_EQ(solution_.reverseWords("a"), "a");
  EXPECT_EQ(solution_.reverseWords("ab cd"), "ba dc");
  EXPECT_EQ(solution_.reverseWords("hello"), "olleh");
}

INSTANTIATE_TEST_SUITE_P(Strategies, ReverseWordsInAStringIiiTest,
                         ::testing::ValuesIn(
                             ReverseWordsInAStringIiiSolution().getStrategyNames()));

}  // namespace leetcode::problem_557
