#include <gtest/gtest.h>
#include "leetcode/problems/frog-position-after-t-seconds.h"

namespace leetcode {
namespace problem_1377 {

namespace {
std::vector<std::vector<int>> buildEdges1() {
  return {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
}
}  // namespace

class FrogPositionAfterTSecondsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FrogPositionAfterTSecondsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FrogPositionAfterTSecondsTest, Example1) {
  auto edges = buildEdges1();
  double r = solution.frogPosition(7, edges, 2, 4);
  EXPECT_NEAR(r, 0.16666666666666666, 1e-5);
}

TEST_P(FrogPositionAfterTSecondsTest, Example2) {
  auto edges = buildEdges1();
  double r = solution.frogPosition(7, edges, 1, 7);
  EXPECT_NEAR(r, 0.3333333333333333, 1e-5);
}

TEST_P(FrogPositionAfterTSecondsTest, SelfAuthoredSingleNodeStays) {
  // n = 1, no edges. Frog stays at vertex 1 forever.
  std::vector<std::vector<int>> edges;
  double r = solution.frogPosition(1, edges, 10, 1);
  EXPECT_NEAR(r, 1.0, 1e-9);
}

TEST_P(FrogPositionAfterTSecondsTest, SelfAuthoredTargetNotEnoughTime) {
  // During Example tree, target 2 at t = 1: prob 1/3.
  auto edges = buildEdges1();
  double r = solution.frogPosition(7, edges, 1, 2);
  EXPECT_NEAR(r, 0.3333333333333333, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    FrogPositionAfterTSeconds, FrogPositionAfterTSecondsTest,
    ::testing::ValuesIn(FrogPositionAfterTSecondsSolution().getStrategyNames()));

}  // namespace problem_1377
}  // namespace leetcode
