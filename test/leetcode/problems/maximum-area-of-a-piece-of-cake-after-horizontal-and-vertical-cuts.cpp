#include "leetcode/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_1465 {

class MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution solution;
};

TEST_P(MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest,
       Example1) {
  int h = 5, w = 4;
  std::vector<int> hCuts = {1, 2, 4};
  std::vector<int> vCuts = {1, 3};
  EXPECT_EQ(4, solution.maxArea(h, w, hCuts, vCuts));
}

TEST_P(MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest,
       Example2) {
  int h = 5, w = 4;
  std::vector<int> hCuts = {3, 1};
  std::vector<int> vCuts = {1};
  EXPECT_EQ(6, solution.maxArea(h, w, hCuts, vCuts));
}

TEST_P(MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest,
       Example3) {
  int h = 5, w = 4;
  std::vector<int> hCuts = {3};
  std::vector<int> vCuts = {3};
  EXPECT_EQ(9, solution.maxArea(h, w, hCuts, vCuts));
}

TEST_P(MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest,
       UnsortedCuts) {
  int h = 5, w = 4;
  std::vector<int> hCuts = {4, 2, 1};
  std::vector<int> vCuts = {3, 1};
  EXPECT_EQ(4, solution.maxArea(h, w, hCuts, vCuts));
}

TEST_P(MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest,
       ModuloOverflow) {
  int h = 1000000000, w = 1000000000;
  std::vector<int> hCuts = {500000000};
  std::vector<int> vCuts = {500000000};
  // maxH = maxV = 500000000, product = 2.5e17; 2.5e17 % (1e9+7) = 250000014
  EXPECT_EQ(250000014, solution.maxArea(h, w, hCuts, vCuts));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTestSuite,
    MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsTest,
    ::testing::ValuesIn(
        MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1465
