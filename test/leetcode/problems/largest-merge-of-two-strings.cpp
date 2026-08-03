#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/largest-merge-of-two-strings.h"

namespace leetcode {
namespace problem_1754 {
namespace {

class LargestMergeOfTwoStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LargestMergeOfTwoStringsSolution solution_;
};

TEST_P(LargestMergeOfTwoStringsTest, Example1) {
  EXPECT_EQ(solution_.largestMerge(std::string("cabaa"), std::string("bcaaa")),
            std::string("cbcabaaaaa"));
}

TEST_P(LargestMergeOfTwoStringsTest, Example2) {
  EXPECT_EQ(solution_.largestMerge(std::string("abcabc"), std::string("abdcaba")),
            std::string("abdcabcabcaba"));
}

TEST_P(LargestMergeOfTwoStringsTest, SelfAuthoredEqualPrefix) {
  EXPECT_EQ(solution_.largestMerge(std::string("a"), std::string("a")),
            std::string("aa"));
}

TEST_P(LargestMergeOfTwoStringsTest, SelfAuthoredEqualCharactersOrder) {
  EXPECT_EQ(solution_.largestMerge(std::string("aaaa"), std::string("aa")),
            std::string("aaaaaa"));
}

INSTANTIATE_TEST_SUITE_P(
    LargestMergeOfTwoStringsTestSuite, LargestMergeOfTwoStringsTest,
    ::testing::ValuesIn(LargestMergeOfTwoStringsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1754
}  // namespace leetcode
