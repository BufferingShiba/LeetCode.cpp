#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-number-of-homogenous-substrings.h"

namespace leetcode {
namespace problem_1759 {

class CountNumberOfHomogenousSubstringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountNumberOfHomogenousSubstringsSolution solution_;
};

TEST_P(CountNumberOfHomogenousSubstringsTest, Example1) {
  EXPECT_EQ(solution_.countHomogenous("abbcccaa"), 13);
}

TEST_P(CountNumberOfHomogenousSubstringsTest, Example2) {
  EXPECT_EQ(solution_.countHomogenous("xy"), 2);
}

TEST_P(CountNumberOfHomogenousSubstringsTest, Example3) {
  EXPECT_EQ(solution_.countHomogenous("zzzzz"), 15);
}

TEST_P(CountNumberOfHomogenousSubstringsTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.countHomogenous("a"), 1);
}

TEST_P(CountNumberOfHomogenousSubstringsTest, SelfAuthoredAllSame) {
  // All 'a', "aaaa" -> 4*5/2 = 10
  EXPECT_EQ(solution_.countHomogenous("aaaa"), 10);
}

TEST_P(CountNumberOfHomogenousSubstringsTest, SelfAuthoredAlternating) {
  // "abab" -> 1+1+1+1 = 4
  EXPECT_EQ(solution_.countHomogenous("abab"), 4);
}

INSTANTIATE_TEST_SUITE_P(
    CountNumberOfHomogenousSubstringsTestSuite,
    CountNumberOfHomogenousSubstringsTest,
    ::testing::ValuesIn(
        CountNumberOfHomogenousSubstringsSolution().getStrategyNames()));

}  // namespace problem_1759
}  // namespace leetcode
