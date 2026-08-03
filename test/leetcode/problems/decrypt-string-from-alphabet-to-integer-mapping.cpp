#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/decrypt-string-from-alphabet-to-integer-mapping.h"

namespace leetcode::problem_1309 {

using DecryptStringFromAlphabetToIntegerMappingTest =
    ::testing::TestWithParam<std::string>;

class DecryptSuite
    : public DecryptStringFromAlphabetToIntegerMappingTest {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DecryptStringFromAlphabetToIntegerMappingSolution solution;
};

TEST_P(DecryptSuite, Example1) {
  EXPECT_EQ(solution.freqAlphabets("10#11#12"), "jkab");
}

TEST_P(DecryptSuite, Example2) {
  EXPECT_EQ(solution.freqAlphabets("1326#"), "acz");
}

TEST_P(DecryptSuite, SingleDigitMapping) {
  EXPECT_EQ(solution.freqAlphabets("123456789"), "abcdefghi");
}

TEST_P(DecryptSuite, MixedMapping) {
  EXPECT_EQ(solution.freqAlphabets("10#26#19#"), "jzs");
}

INSTANTIATE_TEST_SUITE_P(
    DecryptStringFromAlphabetToIntegerMappingTests, DecryptSuite,
    ::testing::ValuesIn(
        DecryptStringFromAlphabetToIntegerMappingSolution::strategyNames()));

}  // namespace leetcode::problem_1309
