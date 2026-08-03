#include <gtest/gtest.h>

#include "leetcode/problems/prefix-and-suffix-search.h"

using namespace leetcode::problem_745;

class PrefixAndSuffixSearchTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

// Official Example 1
TEST_P(PrefixAndSuffixSearchTest, Example1) {
  std::vector<std::string> words = {"apple"};
  WordFilter wf(words);
  EXPECT_EQ(wf.f("a", "e"), 0);
}

// No match
TEST_P(PrefixAndSuffixSearchTest, NoMatch) {
  std::vector<std::string> words = {"apple"};
  WordFilter wf(words);
  EXPECT_EQ(wf.f("b", "e"), -1);
  EXPECT_EQ(wf.f("a", "f"), -1);
  EXPECT_EQ(wf.f("xyz", "abc"), -1);
}

// Multiple words, returns largest index
TEST_P(PrefixAndSuffixSearchTest, LargestIndex) {
  std::vector<std::string> words = {"apple", "banana", "apply", "apricot"};
  WordFilter wf(words);
  // "ap" + "e": only "apple" (idx 0) matches, "apply" ends with 'y'
  EXPECT_EQ(wf.f("ap", "e"), 0);
  // "ap" + "y": "apple" ends with 'e', "apply" (idx 2) ends with 'y'
  EXPECT_EQ(wf.f("ap", "y"), 2);
  // "b" + "a": only "banana" (idx 1)
  EXPECT_EQ(wf.f("b", "a"), 1);
  // "ap" + "ot": only "apricot" (idx 3)
  EXPECT_EQ(wf.f("ap", "ot"), 3);
}

// Full word as prefix/suffix
TEST_P(PrefixAndSuffixSearchTest, FullWord) {
  std::vector<std::string> words = {"abc", "abcd"};
  WordFilter wf(words);
  EXPECT_EQ(wf.f("abc", "abc"), 0);
  EXPECT_EQ(wf.f("abc", "c"), 0);
  EXPECT_EQ(wf.f("abcd", "abcd"), 1);
}

// Overlapping prefix and suffix
TEST_P(PrefixAndSuffixSearchTest, Overlapping) {
  std::vector<std::string> words = {"aaa"};
  WordFilter wf(words);
  EXPECT_EQ(wf.f("aa", "aa"), 0);
}

// Single character words
TEST_P(PrefixAndSuffixSearchTest, SingleChar) {
  std::vector<std::string> words = {"a", "b", "c"};
  WordFilter wf(words);
  EXPECT_EQ(wf.f("a", "a"), 0);
  EXPECT_EQ(wf.f("b", "b"), 1);
  EXPECT_EQ(wf.f("c", "c"), 2);
}

INSTANTIATE_TEST_SUITE_P(All, PrefixAndSuffixSearchTest, ::testing::Values(0));
