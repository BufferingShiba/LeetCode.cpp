#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reorganize-string.h"

namespace leetcode {
namespace problem_767 {
namespace {

bool isValidRearrangement(const std::string& orig, const std::string& result) {
  if (result.empty()) return false;
  if (result.size() != orig.size()) return false;
  for (size_t i = 0; i + 1 < result.size(); ++i) {
    if (result[i] == result[i + 1]) return false;
  }
  // 确认是同一组字符的重排
  std::vector<int> a(26, 0), b(26, 0);
  for (char c : orig) a[c - 'a']++;
  for (char c : result) b[c - 'a']++;
  return a == b;
}

bool isSameMultiset(const std::string& a, const std::string& b) {
  std::vector<int> ca(26, 0), cb(26, 0);
  for (char c : a) ca[c - 'a']++;
  for (char c : b) cb[c - 'a']++;
  return ca == cb;
}

}  // namespace

class ReorganizeStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReorganizeStringSolution solution;
};

TEST_P(ReorganizeStringTest, Example1) {
  std::string s = "aab";
  auto r = solution.reorganizeString(s);
  if (r.empty()) {
    FAIL() << "'aab' should have a valid rearrangement";
  }
  EXPECT_TRUE(isValidRearrangement(s, r));
}

TEST_P(ReorganizeStringTest, Example2) {
  std::string s = "aaab";
  EXPECT_TRUE(solution.reorganizeString(s).empty());
}

TEST_P(ReorganizeStringTest, SelfAuthoredSingleChar) {
  std::string s = "a";
  EXPECT_EQ(solution.reorganizeString(s), "a");
}

TEST_P(ReorganizeStringTest, SelfAuthoredTwoDistinctChar) {
  std::string s = "aaabb";
  auto r = solution.reorganizeString(s);
  if (r.empty()) {
    FAIL() << "'aaabb' should have a valid rearrangement";
  }
  EXPECT_TRUE(isValidRearrangement(s, r));
}

TEST_P(ReorganizeStringTest, SelfAuthoredAllSame) {
  std::string s = "aaaa";
  EXPECT_TRUE(solution.reorganizeString(s).empty());
}

TEST_P(ReorganizeStringTest, SelfAuthoredMaxCountHalfBoundary) {
  // "aabb", maxCount=2, n=4, (4+1)/2=2, feasible
  std::string s = "aabb";
  auto r = solution.reorganizeString(s);
  if (r.empty()) {
    FAIL() << "'aabb' should have a valid rearrangement";
  }
  EXPECT_TRUE(isValidRearrangement(s, r));
}

TEST_P(ReorganizeStringTest, SelfAuthoredClassicTrickyCase) {
  // "vvvlo" -> maxCount('v')=3, n=5, (5+1)/2=3, feasible: "ovlvv"? need valid
  std::string s = "vvvlo";
  auto r = solution.reorganizeString(s);
  if (r.empty()) {
    FAIL() << "'vvvlo' should have a valid rearrangement";
  }
  EXPECT_TRUE(isValidRearrangement(s, r));
}

INSTANTIATE_TEST_SUITE_P(ReorganizeStringTests, ReorganizeStringTest,
                         ::testing::ValuesIn(ReorganizeStringSolution().getStrategyNames()));

}  // namespace problem_767
}  // namespace leetcode
