#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/majority-frequency-characters.h"

namespace leetcode {
namespace problem_3692 {

class MajorityFrequencyCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MajorityFrequencyCharactersSolution solution;
};

TEST_P(MajorityFrequencyCharactersTest, Example1) {
  std::string result = solution.majorityFrequencyGroup("aaabbbccdddde");
  EXPECT_TRUE(result == "ab" || result == "ba");
}

TEST_P(MajorityFrequencyCharactersTest, Example2) {
  EXPECT_EQ(solution.majorityFrequencyGroup("abcd"), "abcd");
}

TEST_P(MajorityFrequencyCharactersTest, Example3) {
  std::string result = solution.majorityFrequencyGroup("pfpfgi");
  EXPECT_TRUE(result == "fp" || result == "pf");
}

TEST_P(MajorityFrequencyCharactersTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.majorityFrequencyGroup("zzz"), "z");
}

TEST_P(MajorityFrequencyCharactersTest, SelfAuthoredAllSameFrequencyTiesPickLargerK) {
  // "aabbcc" : each appears twice; only group is k=2.
  EXPECT_EQ(solution.majorityFrequencyGroup("aabbcc"), "abc");
}

INSTANTIATE_TEST_SUITE_P(
    MajorityFrequencyCharactersTestSuite, MajorityFrequencyCharactersTest,
    ::testing::ValuesIn(MajorityFrequencyCharactersSolution().getStrategyNames()));

}  // namespace problem_3692
}  // namespace leetcode
