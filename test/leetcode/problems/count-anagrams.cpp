#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-anagrams.h"

namespace leetcode {
namespace problem_2514 {

class CountAnagramsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CountAnagramsSolution solution_;
};

TEST_P(CountAnagramsTest, Example1) {
  EXPECT_EQ(18, solution_.countAnagrams("too hot"));
}

TEST_P(CountAnagramsTest, Example2) {
  EXPECT_EQ(1, solution_.countAnagrams("aa"));
}

TEST_P(CountAnagramsTest, SelfAuthoredSingleLetterWord) {
  EXPECT_EQ(1, solution_.countAnagrams("a"));
}

TEST_P(CountAnagramsTest, SelfAuthoredAllDistinctLetters) {
  // "abc" permutations: 3! = 6
  EXPECT_EQ(6, solution_.countAnagrams("abc"));
}

TEST_P(CountAnagramsTest, SelfAuthoredMultipleWords) {
  // "too" -> 3!/(2!) = 3; "hot" -> 3! = 6; total = 18
  EXPECT_EQ(18, solution_.countAnagrams("too hot"));
}

TEST_P(CountAnagramsTest, SelfAuthoredRepeatedWordManyDuplicates) {
  // "aaabbb" -> 6!/(3!*3!) = 20
  EXPECT_EQ(20, solution_.countAnagrams("aaabbb"));
}

TEST_P(CountAnagramsTest, SelfAuthoredTwoIdenticalWords) {
  // "ab" -> 2 permutations; "ab" -> 2; total = 4
  EXPECT_EQ(4, solution_.countAnagrams("ab ab"));
}

INSTANTIATE_TEST_SUITE_P(
    CountAnagramsTestSuite, CountAnagramsTest,
    testing::ValuesIn(CountAnagramsSolution().getStrategyNames()));

}  // namespace problem_2514
}  // namespace leetcode
