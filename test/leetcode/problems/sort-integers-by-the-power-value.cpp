#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sort-integers-by-the-power-value.h"

namespace leetcode {
namespace problem_1387 {

class SortIntegersByThePowerValueTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SortIntegersByThePowerValueSolution solution;
};

TEST_P(SortIntegersByThePowerValueTest, Example1) {
  EXPECT_EQ(solution.getKth(12, 15, 2), 13);
}

TEST_P(SortIntegersByThePowerValueTest, Example2) {
  EXPECT_EQ(solution.getKth(7, 11, 4), 7);
}

TEST_P(SortIntegersByThePowerValueTest, SelfAuthoredSingleElement) {
  EXPECT_EQ(solution.getKth(1, 1, 1), 1);
}

TEST_P(SortIntegersByThePowerValueTest, SelfAuthoredFullRangeK1) {
  // power of 1 is 0, so k=1 returns 1.
  EXPECT_EQ(solution.getKth(1, 1000, 1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    SortIntegersByThePowerValueTestSuite,
    SortIntegersByThePowerValueTest,
    ::testing::ValuesIn(SortIntegersByThePowerValueSolution().getStrategyNames()));

}  // namespace problem_1387
}  // namespace leetcode
