#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/find-substring-with-given-hash-value.h"

namespace leetcode::problem_2156 {

class FindSubstringWithGivenHashValueTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindSubstringWithGivenHashValueSolution solution_;
};

TEST_P(FindSubstringWithGivenHashValueTest, Example1) {
  std::string s = "leetcode";
  int power = 7, modulo = 20, k = 2, hashValue = 0;
  EXPECT_EQ(solution_.subStrHash(s, power, modulo, k, hashValue), "ee");
}

TEST_P(FindSubstringWithGivenHashValueTest, Example2) {
  std::string s = "fbxzaad";
  int power = 31, modulo = 100, k = 3, hashValue = 32;
  EXPECT_EQ(solution_.subStrHash(s, power, modulo, k, hashValue), "fbx");
}

TEST_P(FindSubstringWithGivenHashValueTest, SelfAuthoredSingleChar) {
  std::string s = "a";
  int power = 10, modulo = 100, k = 1, hashValue = 1;
  EXPECT_EQ(solution_.subStrHash(s, power, modulo, k, hashValue), "a");
}

TEST_P(FindSubstringWithGivenHashValueTest, SelfAuthoredFullString) {
  std::string s = "abc";
  int power = 2, modulo = 100, k = 3, hashValue =
      (1 * 1 + 2 * 2 + 3 * 4) % 100;  // = 17
  EXPECT_EQ(solution_.subStrHash(s, power, modulo, k, hashValue), "abc");
}

TEST_P(FindSubstringWithGivenHashValueTest, SelfAuthoredModuloOne) {
  // When modulo = 1, any hash is 0, first substring is the answer.
  std::string s = "abcde";
  int power = 5, modulo = 1, k = 3, hashValue = 0;
  EXPECT_EQ(solution_.subStrHash(s, power, modulo, k, hashValue), "abc");
}

TEST_P(FindSubstringWithGivenHashValueTest, SelfAuthored_Basic) {
  std::string s = "zzzzz";
  // val(z) = 26
  // hash of any length-2 substring: 26 + 26*power
  int power = 5, modulo = 97, k = 2;
  int expected_hash = (26 + 26 * power) % modulo;  // 26 + 130 = 156 % 97 = 59
  EXPECT_EQ(solution_.subStrHash(s, power, modulo, k, expected_hash), "zz");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindSubstringWithGivenHashValueTest,
    testing::ValuesIn(
        FindSubstringWithGivenHashValueSolution().getStrategyNames()));

}  // namespace leetcode::problem_2156
