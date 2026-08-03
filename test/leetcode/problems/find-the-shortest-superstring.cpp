#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-shortest-superstring.h"

namespace leetcode {
namespace problem_943 {

using namespace ::testing;

class FindTheShortestSuperstringTest
    : public TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheShortestSuperstringSolution solution;
};

// Helper: check that `super` contains all words as substrings
bool containsAll(const std::string& super, const std::vector<std::string>& words) {
  for (const auto& w : words) {
    if (super.find(w) == std::string::npos) return false;
  }
  return true;
}

TEST_P(FindTheShortestSuperstringTest, Example1) {
  std::vector<std::string> words = {"alex", "loves", "leetcode"};
  std::string result = solution.shortestSuperstring(words);
  EXPECT_TRUE(containsAll(result, words));
  // No overlap between any pair: 4 + 5 + 8 = 17
  EXPECT_EQ(result.size(), 17);
}

TEST_P(FindTheShortestSuperstringTest, Example2) {
  std::vector<std::string> words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  std::string result = solution.shortestSuperstring(words);
  EXPECT_TRUE(containsAll(result, words));
  // Expected shortest length is 16 (e.g., "gctaagttcatgcatc")
  EXPECT_EQ(result.size(), 16);
}

TEST_P(FindTheShortestSuperstringTest, SingleWord) {
  std::vector<std::string> words = {"hello"};
  std::string result = solution.shortestSuperstring(words);
  EXPECT_EQ(result, "hello");
}

TEST_P(FindTheShortestSuperstringTest, TwoWordsWithOverlap) {
  std::vector<std::string> words = {"abc", "bcd"};
  std::string result = solution.shortestSuperstring(words);
  EXPECT_TRUE(containsAll(result, words));
  // "abc" + "bcd" with overlap "bc" → "abcd" length 4
  EXPECT_EQ(result.size(), 4);
  EXPECT_EQ(result, "abcd");
}

TEST_P(FindTheShortestSuperstringTest, NoOverlap) {
  std::vector<std::string> words = {"ab", "cd", "ef"};
  std::string result = solution.shortestSuperstring(words);
  EXPECT_TRUE(containsAll(result, words));
  // No overlaps, sum = 6
  EXPECT_EQ(result.size(), 6);
}

TEST_P(FindTheShortestSuperstringTest, NestedOverlaps) {
  // "abcde" + "cdefg" overlap "cde" (3) → "abcdefg"
  // then + "efghi" overlap "efg" (3) → "abcdefghi" (9)
  std::vector<std::string> words = {"abcde", "cdefg", "efghi"};
  std::string result = solution.shortestSuperstring(words);
  EXPECT_TRUE(containsAll(result, words));
  EXPECT_EQ(result.size(), 9);
  EXPECT_EQ(result, "abcdefghi");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindTheShortestSuperstringTest,
    ValuesIn(FindTheShortestSuperstringSolution().getStrategyNames()));

}  // namespace problem_943
}  // namespace leetcode
