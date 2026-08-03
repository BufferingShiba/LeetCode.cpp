#include <gtest/gtest.h>

#include "leetcode/problems/to-lower-case.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_709 {
namespace test {

class ToLowerCaseTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ToLowerCaseSolution solution;
};

TEST_P(ToLowerCaseTest, Example1) {
  EXPECT_EQ("hello", solution.toLowerCase("Hello"));
}

TEST_P(ToLowerCaseTest, Example2) {
  EXPECT_EQ("here", solution.toLowerCase("here"));
}

TEST_P(ToLowerCaseTest, Example3) {
  EXPECT_EQ("lovely", solution.toLowerCase("LOVELY"));
}

TEST_P(ToLowerCaseTest, SelfAuthoredMixedCharacters) {
  EXPECT_EQ("hello, world! 123", solution.toLowerCase("Hello, WORLD! 123"));
}

INSTANTIATE_TEST_SUITE_P(ToLowerCaseTestSuite, ToLowerCaseTest,
                         ::testing::ValuesIn(ToLowerCaseSolution().getStrategyNames()));

}  // namespace test
}  // namespace problem_709
}  // namespace leetcode
