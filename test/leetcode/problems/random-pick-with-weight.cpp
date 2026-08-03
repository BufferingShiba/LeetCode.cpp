#include <gtest/gtest.h>

#include "leetcode/problems/random-pick-with-weight.h"

#include <vector>

namespace leetcode::problem_528 {

class RandomPickWithWeightTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

// Single element: only index 0 exists -> always return 0.
TEST_P(RandomPickWithWeightTest, SingleElement) {
  std::vector<int> w{1};
  RandomPickWithWeightSolution sol(w);
  for (int i = 0; i < 200; ++i) {
    EXPECT_EQ(sol.pickIndex(), 0);
  }
}

// Example 2: w = [1, 3]. index 1 has probability ~3/4, index 0 ~1/4.
TEST_P(RandomPickWithWeightTest, SelfAuthoredWeightedDistribution) {
  std::vector<int> w{1, 3};
  RandomPickWithWeightSolution sol(w);
  const int trials = 20000;
  std::vector<int> counts(2, 0);
  for (int i = 0; i < trials; ++i) {
    int idx = sol.pickIndex();
    ASSERT_GE(idx, 0);
    ASSERT_LT(idx, 2);
    counts[idx]++;
  }
  // index 1 should be picked ~75% of the time; use a wide tolerance to avoid flakiness.
  double ratio1 = static_cast<double>(counts[1]) / trials;
  EXPECT_GT(ratio1, 0.68);
  EXPECT_LT(ratio1, 0.82);
  // Both indices must appear (distribution not obviously broken).
  EXPECT_GT(counts[0], 0);
  EXPECT_GT(counts[1], 0);
}

// Larger weights: distribution still contained within valid index range,
// and the heavier index dominates.
TEST_P(RandomPickWithWeightTest, SelfAuthoredLargerWeights) {
  std::vector<int> w{100, 1, 199};
  RandomPickWithWeightSolution sol(w);
  const int trials = 20000;
  std::vector<int> counts(3, 0);
  for (int i = 0; i < trials; ++i) {
    int idx = sol.pickIndex();
    ASSERT_GE(idx, 0);
    ASSERT_LT(idx, 3);
    counts[idx]++;
  }
  // index 2 (~66%), index 0 (~33%), index 1 (~0.3%). Both heavy indices appear.
  EXPECT_GT(counts[2], counts[0]);
  EXPECT_GT(counts[0], counts[1]);
  EXPECT_GT(counts[2], 0);
  EXPECT_GT(counts[0], 0);
}

INSTANTIATE_TEST_SUITE_P(
    RandomPickWithWeightTestParam,
    RandomPickWithWeightTest,
    ::testing::Values(0));

}  // namespace leetcode::problem_528
