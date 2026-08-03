#include "leetcode/problems/lexicographically-smallest-negated-permutation-that-sums-to-target.h"

#include <algorithm>

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3752 {

class LexicographicallySmallestNegatedPermutationThatSumsToTargetTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 3, target = 0
// Output: [-3,1,2]
TEST_P(LexicographicallySmallestNegatedPermutationThatSumsToTargetTest, OfficialExample1) {
  std::vector<int> expected = {-3, 1, 2};
  EXPECT_EQ(expected, solution.lexSmallestNegatedPerm(3, 0));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 1, target = 10000000000
// Output: []
TEST_P(LexicographicallySmallestNegatedPermutationThatSumsToTargetTest, OfficialExample2) {
  std::vector<int> expected;
  EXPECT_EQ(expected, solution.lexSmallestNegatedPerm(1, 10000000000LL));
}

TEST_P(LexicographicallySmallestNegatedPermutationThatSumsToTargetTest,
       ExhaustiveSmallInputs) {
  // Enumerate every choice of negated values for small n.  This checks both
  // feasibility handling and the lexicographic tie-break of the greedy.
  for (int n = 1; n <= 8; ++n) {
    const int total = n * (n + 1) / 2;
    for (long long target = -total; target <= total; ++target) {
      std::vector<int> expected;
      for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = total;
        for (int value = 1; value <= n; ++value) {
          if (mask & (1 << (value - 1))) sum -= 2 * value;
        }
        if (sum != target) continue;

        std::vector<int> candidate;
        for (int value = n; value >= 1; --value) {
          if (mask & (1 << (value - 1))) candidate.push_back(-value);
        }
        for (int value = 1; value <= n; ++value) {
          if (!(mask & (1 << (value - 1)))) candidate.push_back(value);
        }
        if (expected.empty() || candidate < expected) expected = candidate;
      }
      EXPECT_EQ(expected, solution.lexSmallestNegatedPerm(n, target))
          << "n=" << n << ", target=" << target;
    }
  }
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, LexicographicallySmallestNegatedPermutationThatSumsToTargetTest,
    ::testing::ValuesIn(LexicographicallySmallestNegatedPermutationThatSumsToTargetSolution().getStrategyNames()));

}  // namespace problem_3752
}  // namespace leetcode
