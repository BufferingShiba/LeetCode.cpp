#include <gtest/gtest.h>

#include <string>
#include "leetcode/problems/dota2-senate.h"

namespace leetcode {
namespace problem_649 {

class Dota2SenateTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  Dota2SenateSolution solution;
};

TEST_P(Dota2SenateTest, Example1) {
  EXPECT_EQ(solution.predictPartyVictory("RD"), "Radiant");
}

TEST_P(Dota2SenateTest, Example2) {
  EXPECT_EQ(solution.predictPartyVictory("RDD"), "Dire");
}

TEST_P(Dota2SenateTest, SelfAuthoredSingleSenator) {
  EXPECT_EQ(solution.predictPartyVictory("R"), "Radiant");
  EXPECT_EQ(solution.predictPartyVictory("D"), "Dire");
}

TEST_P(Dota2SenateTest, SelfAuthoredAllSameParty) {
  EXPECT_EQ(solution.predictPartyVictory("RRR"), "Radiant");
  EXPECT_EQ(solution.predictPartyVictory("DDD"), "Dire");
}

TEST_P(Dota2SenateTest, SelfAuthoredAlternating) {
  EXPECT_EQ(solution.predictPartyVictory("DRRD"), "Dire");
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    Dota2SenateTest,
    testing::ValuesIn(Dota2SenateSolution().getStrategyNames()));

}  // namespace problem_649
}  // namespace leetcode
