#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-ways-to-select-buildings.h"

namespace leetcode {
namespace problem_2222 {

class NumberOfWaysToSelectBuildingsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfWaysToSelectBuildingsSolution solution_;
};

TEST_P(NumberOfWaysToSelectBuildingsTest, Example1) {
  EXPECT_EQ(6, solution_.numberOfWays("001101"));
}

TEST_P(NumberOfWaysToSelectBuildingsTest, Example2) {
  EXPECT_EQ(0, solution_.numberOfWays("11100"));
}

TEST_P(NumberOfWaysToSelectBuildingsTest, AllSameType) {
  EXPECT_EQ(0, solution_.numberOfWays("11111"));
}

TEST_P(NumberOfWaysToSelectBuildingsTest, SelfAuthoredAlternating) {
  // "01010101": 每一组选择的三元组都需交替，共有 20 种
  EXPECT_EQ(20, solution_.numberOfWays("01010101"));
}

TEST_P(NumberOfWaysToSelectBuildingsTest, MixedMinimum) {
  // "010": 只有 [0,1,2]，一种方案
  EXPECT_EQ(1, solution_.numberOfWays("010"));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfWaysToSelectBuildingsTestSuite,
    NumberOfWaysToSelectBuildingsTest,
    ::testing::ValuesIn(NumberOfWaysToSelectBuildingsSolution().getStrategyNames()));

}  // namespace problem_2222
}  // namespace leetcode
