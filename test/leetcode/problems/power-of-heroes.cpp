#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/power-of-heroes.h"

namespace leetcode {
namespace problem_2681 {
namespace {

class PowerOfHeroesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PowerOfHeroesSolution solution;
};

TEST_P(PowerOfHeroesTest, Example1) {
  std::vector<int> nums{2, 1, 4};
  EXPECT_EQ(141, solution.getSolution()(nums));
}

TEST_P(PowerOfHeroesTest, Example2) {
  std::vector<int> nums{1, 1, 1};
  EXPECT_EQ(7, solution.getSolution()(nums));
}

TEST_P(PowerOfHeroesTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(125, solution.getSolution()(nums));
}

INSTANTIATE_TEST_SUITE_P(PowerOfHeroesTestSuite, PowerOfHeroesTest,
                         ::testing::ValuesIn(PowerOfHeroesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2681
}  // namespace leetcode
