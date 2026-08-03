#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-residue-prefixes.h"

namespace leetcode {
namespace problem_3803 {

class CountResiduePrefixesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountResiduePrefixesSolution solution;
};

TEST_P(CountResiduePrefixesTest, Example1) {
  EXPECT_EQ(solution.residuePrefixes("abc"), 2);
}

TEST_P(CountResiduePrefixesTest, Example2) {
  EXPECT_EQ(solution.residuePrefixes("dd"), 1);
}

TEST_P(CountResiduePrefixesTest, Example3) {
  EXPECT_EQ(solution.residuePrefixes("bob"), 2);
}

TEST_P(CountResiduePrefixesTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.residuePrefixes("a"), 1);
}

TEST_P(CountResiduePrefixesTest, SelfAuthoredAllSameNoResidueLong) {
  // "aaa": prefix3 distinct=1, len_mod=0 -> not residue; prefix1(1=1 yes), prefix2(1!=2 no)
  EXPECT_EQ(solution.residuePrefixes("aaa"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountResiduePrefixesTestSuites, CountResiduePrefixesTest,
    ::testing::ValuesIn(CountResiduePrefixesSolution().getStrategyNames()));

}  // namespace problem_3803
}  // namespace leetcode
