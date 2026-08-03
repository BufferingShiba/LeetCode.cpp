#include "leetcode/problems/reverse-string-ii.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_541 {
namespace test {

class ReverseStringIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReverseStringIiSolution solution;
};

TEST_P(ReverseStringIiTest, Example1) {
  EXPECT_EQ(solution.reverseStr("abcdefg", 2), "bacdfeg");
}

TEST_P(ReverseStringIiTest, Example2) {
  EXPECT_EQ(solution.reverseStr("abcd", 2), "bacd");
}

TEST_P(ReverseStringIiTest, SelfAuthored_SingleChar) {
  EXPECT_EQ(solution.reverseStr("a", 2), "a");
}

TEST_P(ReverseStringIiTest, SelfAuthored_LessThanKLeft) {
  EXPECT_EQ(solution.reverseStr("abc", 5), "cba");
}

TEST_P(ReverseStringIiTest, SelfAuthored_KEqualsOne) {
  EXPECT_EQ(solution.reverseStr("abcdef", 1), "abcdef");
}

INSTANTIATE_TEST_SUITE_P(
    ReverseStringIiTestSuite, ReverseStringIiTest,
    ::testing::ValuesIn(ReverseStringIiSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_541
}  // namespace leetcode
