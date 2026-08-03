#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-population-year.h"

namespace leetcode {
namespace problem_1854 {
namespace {

class MaximumPopulationYearTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumPopulationYearSolution solution_;
};

TEST_P(MaximumPopulationYearTest, Example1) {
  std::vector<std::vector<int>> logs = {{1993, 1999}, {2000, 2010}};
  EXPECT_EQ(1993, solution_.maximumPopulation(logs));
}

TEST_P(MaximumPopulationYearTest, Example2) {
  std::vector<std::vector<int>> logs = {
      {1950, 1961}, {1960, 1971}, {1970, 1981}};
  EXPECT_EQ(1960, solution_.maximumPopulation(logs));
}

TEST_P(MaximumPopulationYearTest, SinglePerson) {
  std::vector<std::vector<int>> logs = {{2000, 2001}};
  EXPECT_EQ(2000, solution_.maximumPopulation(logs));
}

TEST_P(MaximumPopulationYearTest, AllAliveOverlap) {
  std::vector<std::vector<int>> logs = {
      {1950, 2050}, {1951, 2050}, {1952, 2050}};
  EXPECT_EQ(1952, solution_.maximumPopulation(logs));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumPopulationYearTestSuite, MaximumPopulationYearTest,
    ::testing::ValuesIn(MaximumPopulationYearSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1854
}  // namespace leetcode
