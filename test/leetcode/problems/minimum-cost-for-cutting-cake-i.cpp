
#include "leetcode/problems/minimum-cost-for-cutting-cake-i.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3218 {

class MinimumCostForCuttingCakeITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumCostForCuttingCakeISolution solution;
};

TEST_P(MinimumCostForCuttingCakeITest, Example1) {
  int m = 3, n = 2;
  std::vector<int> horizontalCut = {1, 3};
  std::vector<int> verticalCut = {5};
  EXPECT_EQ(13, solution.minimumCost(m, n, horizontalCut, verticalCut));
}

TEST_P(MinimumCostForCuttingCakeITest, Example2) {
  int m = 2, n = 2;
  std::vector<int> horizontalCut = {7};
  std::vector<int> verticalCut = {4};
  EXPECT_EQ(15, solution.minimumCost(m, n, horizontalCut, verticalCut));
}

TEST_P(MinimumCostForCuttingCakeITest, SelfAuthoredSingleRow) {
  // m = 1, 只需垂直切
  int m = 1, n = 3;
  std::vector<int> horizontalCut = {};
  std::vector<int> verticalCut = {1, 2};
  // 垂直之间互不影响，每刀乘以系数1，总 = 1 + 2 = 3
  EXPECT_EQ(3, solution.minimumCost(m, n, horizontalCut, verticalCut));
}

TEST_P(MinimumCostForCuttingCakeITest, SelfAuthoredSingleColumn) {
  // n = 1, 只需水平切
  int m = 3, n = 1;
  std::vector<int> horizontalCut = {4, 6};
  std::vector<int> verticalCut = {};
  EXPECT_EQ(10, solution.minimumCost(m, n, horizontalCut, verticalCut));
}

TEST_P(MinimumCostForCuttingCakeITest, SelfAuthoredAlreadyUnit) {
  int m = 1, n = 1;
  std::vector<int> horizontalCut = {};
  std::vector<int> verticalCut = {};
  EXPECT_EQ(0, solution.minimumCost(m, n, horizontalCut, verticalCut));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumCostForCuttingCakeITest,
    ::testing::ValuesIn(MinimumCostForCuttingCakeISolution().getStrategyNames()));

}  // namespace problem_3218
}  // namespace leetcode
