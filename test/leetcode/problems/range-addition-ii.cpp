#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/range-addition-ii.h"

namespace leetcode {
namespace problem_598 {
namespace {

class RangeAdditionIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RangeAdditionIiSolution solution;
};

TEST_P(RangeAdditionIiTest, Example1) {
  int m = 3, n = 3;
  std::vector<std::vector<int>> ops = {{2, 2}, {3, 3}};
  EXPECT_EQ(4, solution.maxCount(m, n, ops));
}

TEST_P(RangeAdditionIiTest, Example2) {
  int m = 3, n = 3;
  std::vector<std::vector<int>> ops = {
      {2, 2}, {3, 3}, {3, 3}, {3, 3}, {2, 2}, {3, 3},
      {3, 3}, {3, 3}, {2, 2}, {3, 3}, {3, 3}, {3, 3}};
  EXPECT_EQ(4, solution.maxCount(m, n, ops));
}

TEST_P(RangeAdditionIiTest, Example3) {
  int m = 3, n = 3;
  std::vector<std::vector<int>> ops = {};
  EXPECT_EQ(9, solution.maxCount(m, n, ops));
}

TEST_P(RangeAdditionIiTest, SelfAuthoredSingleOperationCoversAll) {
  int m = 10, n = 10;
  std::vector<std::vector<int>> ops = {{10, 10}};
  EXPECT_EQ(100, solution.maxCount(m, n, ops));
}

INSTANTIATE_TEST_SUITE_P(
    RangeAdditionIiTestSuite, RangeAdditionIiTest,
    ::testing::ValuesIn(RangeAdditionIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_598
}  // namespace leetcode
