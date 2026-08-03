#include "leetcode/problems/minimum-genetic-mutation.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_433 {

class MinimumGeneticMutationTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumGeneticMutationSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
TEST_P(MinimumGeneticMutationTest, OfficialExample1) {
  string startGene = "AACCGGTT";
  string endGene = "AACCGGTA";
  vector<string> bank = {"AACCGGTA"};
  EXPECT_EQ(1, solution.minMutation(startGene, endGene, bank));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
TEST_P(MinimumGeneticMutationTest, OfficialExample2) {
  string startGene = "AACCGGTT";
  string endGene = "AAACGGTA";
  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  EXPECT_EQ(2, solution.minMutation(startGene, endGene, bank));
}

TEST_P(MinimumGeneticMutationTest, SameStartAndEndNeedsNoMutation) {
  string startGene = "AACCGGTT";
  string endGene = "AACCGGTT";
  vector<string> bank;
  EXPECT_EQ(0, solution.minMutation(startGene, endGene, bank));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumGeneticMutationTest,
    ::testing::ValuesIn(MinimumGeneticMutationSolution().getStrategyNames()));

}  // namespace problem_433
}  // namespace leetcode
