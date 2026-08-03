#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-original-typed-string-i.h"

namespace leetcode {
namespace problem_3330 {

class FindTheOriginalTypedStringITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheOriginalTypedStringISolution solution_;
};

TEST_P(FindTheOriginalTypedStringITest, Example1) {
  EXPECT_EQ(5, solution_.possibleStringCount("abbcccc"));
}

TEST_P(FindTheOriginalTypedStringITest, Example2) {
  EXPECT_EQ(1, solution_.possibleStringCount("abcd"));
}

TEST_P(FindTheOriginalTypedStringITest, Example3) {
  EXPECT_EQ(4, solution_.possibleStringCount("aaaa"));
}

TEST_P(FindTheOriginalTypedStringITest, SelfAuthoredSingleChar) {
  EXPECT_EQ(1, solution_.possibleStringCount("z"));
}

TEST_P(FindTheOriginalTypedStringITest, SelfAuthoredMultipleRuns) {
  EXPECT_EQ(3, solution_.possibleStringCount("aabb"));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheOriginalTypedStringITestSuite, FindTheOriginalTypedStringITest,
    ::testing::ValuesIn(FindTheOriginalTypedStringISolution().getStrategyNames()));

}  // namespace problem_3330
}  // namespace leetcode
