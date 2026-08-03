#include "leetcode/problems/prime-arrangements.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode {
namespace problem_1175 {
namespace {

class PrimeArrangementsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PrimeArrangementsSolution solution;
};

TEST_P(PrimeArrangementsTest, Example1) {
  EXPECT_EQ(solution.numPrimeArrangements(5), 12);
}

TEST_P(PrimeArrangementsTest, Example2) {
  EXPECT_EQ(solution.numPrimeArrangements(100), 682289015);
}

TEST_P(PrimeArrangementsTest, SelfAuthoredEdgeCaseN1) {
  EXPECT_EQ(solution.numPrimeArrangements(1), 1);
}

INSTANTIATE_TEST_SUITE_P(PrimeArrangementsTestSuite, PrimeArrangementsTest,
                         ::testing::ValuesIn(PrimeArrangementsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1175
}  // namespace leetcode
