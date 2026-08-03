#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-resultant-array-after-removing-anagrams.h"

namespace leetcode {
namespace problem_2273 {

class FindResultantArrayAfterRemovingAnagramsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FindResultantArrayAfterRemovingAnagramsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }

  void expectRemoved(const std::vector<std::string>& input,
                     const std::vector<std::string>& expected) {
    std::vector<std::string> words = input;
    EXPECT_EQ(solution.removeAnagrams(words), expected);
  }
};

TEST_P(FindResultantArrayAfterRemovingAnagramsTest, Example1) {
  expectRemoved({"abba", "baba", "bbaa", "cd", "cd"}, {"abba", "cd"});
}

TEST_P(FindResultantArrayAfterRemovingAnagramsTest, Example2) {
  expectRemoved({"a", "b", "c", "d", "e"}, {"a", "b", "c", "d", "e"});
}

TEST_P(FindResultantArrayAfterRemovingAnagramsTest, SelfAuthoredSingleWord) {
  expectRemoved({"hello"}, {"hello"});
}

TEST_P(FindResultantArrayAfterRemovingAnagramsTest, SelfAuthoredAllSameAnagram) {
  expectRemoved({"abc", "bac", "cba"}, {"abc"});
}

TEST_P(FindResultantArrayAfterRemovingAnagramsTest, SelfAuthoredNonAdjacentKept) {
  // "ab" and "ba" are anagrams but not adjacent, so nothing is removed.
  expectRemoved({"ab", "cd", "ba"}, {"ab", "cd", "ba"});
}

INSTANTIATE_TEST_SUITE_P(
    FindResultantArrayAfterRemovingAnagramsTest, FindResultantArrayAfterRemovingAnagramsTest,
    ::testing::ValuesIn(
        FindResultantArrayAfterRemovingAnagramsSolution().getStrategyNames()));

}  // namespace problem_2273
}  // namespace leetcode
