#include <gtest/gtest.h>

#include "leetcode/problems/partition-string-into-minimum-beautiful-substrings.h"

namespace leetcode::problem_2767 {

class PartitionStringIntoMinimumBeautifulSubstringsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  PartitionStringIntoMinimumBeautifulSubstringsSolution solution;
};

TEST_P(PartitionStringIntoMinimumBeautifulSubstringsTest, Example1) {
  EXPECT_EQ(solution.minimumBeautifulSubstrings("1011"), 2);
}

TEST_P(PartitionStringIntoMinimumBeautifulSubstringsTest, Example2) {
  EXPECT_EQ(solution.minimumBeautifulSubstrings("111"), 3);
}

TEST_P(PartitionStringIntoMinimumBeautifulSubstringsTest, Example3) {
  EXPECT_EQ(solution.minimumBeautifulSubstrings("0"), -1);
}

TEST_P(PartitionStringIntoMinimumBeautifulSubstringsTest, SelfAuthoredEdgeCases) {
  EXPECT_EQ(solution.minimumBeautifulSubstrings("1"), 1);
  EXPECT_EQ(solution.minimumBeautifulSubstrings("101"), 1);
  EXPECT_EQ(solution.minimumBeautifulSubstrings("11001"), 1);
  EXPECT_EQ(solution.minimumBeautifulSubstrings("0000"), -1);
  EXPECT_EQ(solution.minimumBeautifulSubstrings("10"), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    PartitionStringIntoMinimumBeautifulSubstringsTest,
    ::testing::ValuesIn(PartitionStringIntoMinimumBeautifulSubstringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2767
