#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/repeated-dna-sequences.h"

using namespace leetcode::problem_187;

class RepeatedDnaSequencesTest : public ::testing::TestWithParam<std::string> {
 protected:
  RepeatedDnaSequencesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(RepeatedDnaSequencesTest, Example1) {
  auto result =
      solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  std::vector<std::string> expected = {"AAAAACCCCC", "CCCCCAAAAA"};
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(RepeatedDnaSequencesTest, Example2) {
  auto result = solution.findRepeatedDnaSequences("AAAAAAAAAAAAA");
  std::vector<std::string> expected = {"AAAAAAAAAA"};
  EXPECT_EQ(result, expected);
}

TEST_P(RepeatedDnaSequencesTest, NoRepeat) {
  auto result = solution.findRepeatedDnaSequences("ACGTACGTAC");
  EXPECT_TRUE(result.empty());
}

TEST_P(RepeatedDnaSequencesTest, AllSameShort) {
  auto result = solution.findRepeatedDnaSequences("AAAAAAAAAA");
  EXPECT_TRUE(result.empty());
}

TEST_P(RepeatedDnaSequencesTest, SimpleRepeat) {
  // "AAAAACCCCC" appears twice at positions 0 and 10
  auto result =
      solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCC");
  std::vector<std::string> expected = {"AAAAACCCCC"};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, RepeatedDnaSequencesTest,
                         ::testing::ValuesIn(RepeatedDnaSequencesSolution()
                                                 .getStrategyNames()));
