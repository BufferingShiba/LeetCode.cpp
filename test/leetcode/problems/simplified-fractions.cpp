#include "leetcode/problems/simplified-fractions.h"

#include <gtest/gtest.h>

#include <algorithm>

namespace leetcode {
namespace problem_1447 {

class SimplifiedFractionsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SimplifiedFractionsSolution solution;
};

TEST_P(SimplifiedFractionsTest, Example1) {
  auto actual = solution.simplifiedFractions(2);
  std::vector<std::string> expected = {"1/2"};
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

TEST_P(SimplifiedFractionsTest, Example2) {
  auto actual = solution.simplifiedFractions(3);
  std::vector<std::string> expected = {"1/2", "1/3", "2/3"};
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

TEST_P(SimplifiedFractionsTest, Example3) {
  auto actual = solution.simplifiedFractions(4);
  std::vector<std::string> expected = {"1/2", "1/3", "1/4", "2/3",
                                       "3/4"};
  std::sort(actual.begin(), actual.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, actual);
}

TEST_P(SimplifiedFractionsTest, SelfAuthoredNOne) {
  EXPECT_TRUE(solution.simplifiedFractions(1).empty());
}

INSTANTIATE_TEST_SUITE_P(
    SimplifiedFractionsTestSuite, SimplifiedFractionsTest,
    ::testing::ValuesIn(SimplifiedFractionsSolution().getStrategyNames()));

}  // namespace problem_1447
}  // namespace leetcode
