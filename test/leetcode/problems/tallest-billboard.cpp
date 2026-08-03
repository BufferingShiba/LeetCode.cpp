#include <gtest/gtest.h>

#include "leetcode/problems/tallest-billboard.h"

#include <string>
#include <vector>

using leetcode::problem_956::TallestBillboardSolution;

namespace {

class TallestBillboardTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TallestBillboardSolution solution_;
};

TEST_P(TallestBillboardTest, Example1) {
  std::vector<int> rods{1, 2, 3, 6};
  EXPECT_EQ(solution_.tallestBillboard(rods), 6);
}

TEST_P(TallestBillboardTest, Example2) {
  std::vector<int> rods{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(solution_.tallestBillboard(rods), 10);
}

TEST_P(TallestBillboardTest, Example3) {
  std::vector<int> rods{1, 2};
  EXPECT_EQ(solution_.tallestBillboard(rods), 0);
}

TEST_P(TallestBillboardTest, SelfAuthoredSingleRod) {
  std::vector<int> rods{1};
  EXPECT_EQ(solution_.tallestBillboard(rods), 0);
}

TEST_P(TallestBillboardTest, SelfAuthoredEqualRods) {
  std::vector<int> rods{3, 3, 3, 3};
  EXPECT_EQ(solution_.tallestBillboard(rods), 6);
}

TEST_P(TallestBillboardTest, SelfAuthoredSinglePair) {
  std::vector<int> rods{2, 2};
  EXPECT_EQ(solution_.tallestBillboard(rods), 2);
}

INSTANTIATE_TEST_SUITE_P(
    TallestBillboardStrategies, TallestBillboardTest,
    ::testing::ValuesIn(TallestBillboardSolution().getStrategyNames()));

}  // namespace
