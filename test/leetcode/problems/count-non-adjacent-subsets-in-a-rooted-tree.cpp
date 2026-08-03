#include <gtest/gtest.h>
#include "leetcode/problems/count-non-adjacent-subsets-in-a-rooted-tree.h"

namespace leetcode {
namespace problem_3939 {

class CountNonAdjacentSubsetsInARootedTreeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  CountNonAdjacentSubsetsInARootedTreeSolution solution_;
};

TEST_P(CountNonAdjacentSubsetsInARootedTreeTest, Example1) {
  std::vector<int> parent = {-1, 0, 1};
  std::vector<int> nums = {1, 2, 3};
  int k = 3;
  EXPECT_EQ(solution_.countValidSubsets(parent, nums, k), 1);
}

TEST_P(CountNonAdjacentSubsetsInARootedTreeTest, Example2) {
  std::vector<int> parent = {-1, 0, 0, 0};
  std::vector<int> nums = {2, 1, 2, 1};
  int k = 3;
  EXPECT_EQ(solution_.countValidSubsets(parent, nums, k), 2);
}

INSTANTIATE_TEST_SUITE_P(
    CountNonAdjacentSubsetsInARootedTree,
    CountNonAdjacentSubsetsInARootedTreeTest,
    testing::ValuesIn(CountNonAdjacentSubsetsInARootedTreeSolution().getStrategyNames()));

}  // namespace problem_3939
}  // namespace leetcode
