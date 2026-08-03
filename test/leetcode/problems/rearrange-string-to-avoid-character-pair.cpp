#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/rearrange-string-to-avoid-character-pair.h"

namespace leetcode::problem_3992 {
namespace {

class RearrangeStringToAvoidCharacterPairTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RearrangeStringToAvoidCharacterPairSolution solution_;

  static bool isValid(const std::string& t, const std::string& s, char x, char y) {
    // t must be a permutation of s
    int cnt[26] = {0};
    for (char c : s) ++cnt[c - 'a'];
    for (char c : t) --cnt[c - 'a'];
    for (int i = 0; i < 26; ++i)
      if (cnt[i] != 0) return false;

    // every y must appear before every x
    int lastY = -1;
    int firstX = -1;
    for (int i = 0; i < static_cast<int>(t.size()); ++i) {
      if (t[i] == y) lastY = i;
      if (t[i] == x && firstX == -1) firstX = i;
    }
    return !(lastY != -1 && firstX != -1 && lastY > firstX);
  }
};

TEST_P(RearrangeStringToAvoidCharacterPairTest, Example1) {
  auto t = solution_.rearrangeString("aabc", 'a', 'c');
  EXPECT_TRUE(isValid(t, "aabc", 'a', 'c'));
}

TEST_P(RearrangeStringToAvoidCharacterPairTest, Example2) {
  auto t = solution_.rearrangeString("dcab", 'd', 'b');
  EXPECT_TRUE(isValid(t, "dcab", 'd', 'b'));
}

TEST_P(RearrangeStringToAvoidCharacterPairTest, Example3) {
  auto t = solution_.rearrangeString("axe", 'o', 'x');
  EXPECT_TRUE(isValid(t, "axe", 'o', 'x'));
}

INSTANTIATE_TEST_SUITE_P(Strategies, RearrangeStringToAvoidCharacterPairTest,
                         testing::ValuesIn(RearrangeStringToAvoidCharacterPairSolution()
                                               .getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_3992
