#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/jewels-and-stones.h"

namespace leetcode {
namespace problem_771 {

class JewelsAndStonesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  JewelsAndStonesSolution solution;
};

TEST_P(JewelsAndStonesTest, Example1) {
  EXPECT_EQ(solution.numJewelsInStones("aA", "aAAbbbb"), 3);
}

TEST_P(JewelsAndStonesTest, Example2) {
  EXPECT_EQ(solution.numJewelsInStones("z", "ZZ"), 0);
}

TEST_P(JewelsAndStonesTest, SelfAuthoredAllJewels) {
  EXPECT_EQ(solution.numJewelsInStones("abc", "abcabc"), 6);
}

TEST_P(JewelsAndStonesTest, SelfAuthoredNoJewels) {
  EXPECT_EQ(solution.numJewelsInStones("z", "abcDEF"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    JewelsAndStonesTestSuite, JewelsAndStonesTest,
    ::testing::ValuesIn(JewelsAndStonesSolution().getStrategyNames()));

}  // namespace problem_771
}  // namespace leetcode
