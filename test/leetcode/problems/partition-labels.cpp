#include <gtest/gtest.h>

#include "leetcode/problems/partition-labels.h"

using namespace leetcode::problem_763;

class PartitionLabelsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  PartitionLabelsSolution solution_;
};

TEST_P(PartitionLabelsTest, Example1) {
  std::string s = "ababcbacadefegdehijhklij";
  std::vector<int> expected = {9, 7, 8};
  EXPECT_EQ(solution_.partitionLabels(s), expected);
}

TEST_P(PartitionLabelsTest, Example2) {
  std::string s = "eccbbbbdec";
  std::vector<int> expected = {10};
  EXPECT_EQ(solution_.partitionLabels(s), expected);
}

TEST_P(PartitionLabelsTest, SelfAuthoredSingleChar) {
  std::string s = "a";
  std::vector<int> expected = {1};
  EXPECT_EQ(solution_.partitionLabels(s), expected);
}

TEST_P(PartitionLabelsTest, SelfAuthoredAllSame) {
  std::string s = "aaaa";
  std::vector<int> expected = {4};
  EXPECT_EQ(solution_.partitionLabels(s), expected);
}

TEST_P(PartitionLabelsTest, SelfAuthoredAlternating) {
  std::string s = "abab";
  std::vector<int> expected = {4};
  EXPECT_EQ(solution_.partitionLabels(s), expected);
}

INSTANTIATE_TEST_SUITE_P(All,
                         PartitionLabelsTest,
                         testing::ValuesIn(PartitionLabelsSolution().getStrategyNames()));
