#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/semi-ordered-permutation.h"

namespace leetcode {
namespace problem_2717 {

class SemiOrderedPermutationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SemiOrderedPermutationSolution solution;
};

TEST_P(SemiOrderedPermutationTest, Example1) {
  std::vector<int> nums{2, 1, 4, 3};
  EXPECT_EQ(solution.getSolution()(nums), 2);
}

TEST_P(SemiOrderedPermutationTest, Example2) {
  std::vector<int> nums{2, 4, 1, 3};
  EXPECT_EQ(solution.getSolution()(nums), 3);
}

TEST_P(SemiOrderedPermutationTest, Example3) {
  std::vector<int> nums{1, 3, 4, 2, 5};
  EXPECT_EQ(solution.getSolution()(nums), 0);
}

TEST_P(SemiOrderedPermutationTest, ReverseOrder) {
  std::vector<int> nums{4, 3, 2, 1};
  // n=4, p1=3 (index of 1), pn=0 (index of 4)
  // ans = 3 + (3-0) - 1 = 5
  EXPECT_EQ(solution.getSolution()(nums), 5);
}

TEST_P(SemiOrderedPermutationTest, AlreadyOrdered) {
  std::vector<int> nums{1, 2};
  EXPECT_EQ(solution.getSolution()(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    SemiOrderedPermutationTestSuite, SemiOrderedPermutationTest,
    ::testing::ValuesIn(SemiOrderedPermutationSolution().getStrategyNames()));

}  // namespace problem_2717
}  // namespace leetcode
