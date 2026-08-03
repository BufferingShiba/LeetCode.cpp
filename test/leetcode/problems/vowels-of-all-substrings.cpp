#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/vowels-of-all-substrings.h"

namespace leetcode::problem_2063 {
namespace {

class VowelsOfAllSubstringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  VowelsOfAllSubstringsSolution solution_;
};

TEST_P(VowelsOfAllSubstringsTest, Example1) {
  EXPECT_EQ(6, solution_.countVowels("aba"));
}

TEST_P(VowelsOfAllSubstringsTest, Example2) {
  EXPECT_EQ(3, solution_.countVowels("abc"));
}

TEST_P(VowelsOfAllSubstringsTest, Example3) {
  EXPECT_EQ(0, solution_.countVowels("ltcd"));
}

TEST_P(VowelsOfAllSubstringsTest, SingleVowel) {
  EXPECT_EQ(1, solution_.countVowels("a"));
}

TEST_P(VowelsOfAllSubstringsTest, AllVowels) {
  // substrings of "aua": a,au,aua,u,ua,a -> vowel counts 1+2+3+1+2+1 = 10.
  EXPECT_EQ(10, solution_.countVowels("aua"));
}

INSTANTIATE_TEST_SUITE_P(VowelsOfAllSubstringsTestSuite,
                         VowelsOfAllSubstringsTest,
                         ::testing::ValuesIn(
                             VowelsOfAllSubstringsSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2063
