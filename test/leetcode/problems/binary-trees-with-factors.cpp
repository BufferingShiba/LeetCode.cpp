#include "leetcode/problems/binary-trees-with-factors.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_823 {

class BinaryTreesWithFactorsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BinaryTreesWithFactorsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  arr = [2,4]
// Output: 3
TEST_P(BinaryTreesWithFactorsTest, OfficialExample1) {
  std::vector<int> arr = {2, 4};
  EXPECT_EQ(3, solution.numFactoredBinaryTrees(arr));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  arr = [2,4,5,10]
// Output: 7
TEST_P(BinaryTreesWithFactorsTest, OfficialExample2) {
  std::vector<int> arr = {2, 4, 5, 10};
  EXPECT_EQ(7, solution.numFactoredBinaryTrees(arr));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, BinaryTreesWithFactorsTest,
    ::testing::ValuesIn(BinaryTreesWithFactorsSolution().getStrategyNames()));

}  // namespace problem_823
}  // namespace leetcode
