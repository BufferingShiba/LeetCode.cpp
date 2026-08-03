#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/maximum-genetic-difference-query.h"

namespace leetcode {
namespace problem_1938 {

class MaximumGeneticDifferenceQueryTest : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  MaximumGeneticDifferenceQuerySolution solution_;
};

TEST_P(MaximumGeneticDifferenceQueryTest, Example1) {
  std::vector<int> parents = {-1, 0, 1, 1};
  std::vector<std::vector<int>> queries = {{0, 2}, {3, 2}, {2, 5}};
  std::vector<int> expected = {2, 3, 7};
  std::vector<int> actual = solution_.getSolution()(parents, queries);
  EXPECT_EQ(actual, expected);
}

TEST_P(MaximumGeneticDifferenceQueryTest, Example2) {
  std::vector<int> parents = {3, 7, -1, 2, 0, 7, 0, 2};
  std::vector<std::vector<int>> queries = {{4, 6}, {1, 15}, {0, 5}};
  std::vector<int> expected = {6, 14, 7};
  std::vector<int> actual = solution_.getSolution()(parents, queries);
  EXPECT_EQ(actual, expected);
}

TEST_P(MaximumGeneticDifferenceQueryTest, SelfAuthoredSingleChainPathToRoot) {
  // parents: 0 root, 1 child of 0, 2 child of 1, 3 child of 2
  std::vector<int> parents = {-1, 0, 1, 2};
  std::vector<std::vector<int>> queries = {{3, 0}, {3, 7}, {1, 15}};
  // Path for node 3: {0,1,2,3} -> max XOR with 0 is 3.
  // Path for node 3: {0,1,2,3} -> max XOR with 7: 7^3=4,7^2=5,7^1=6,7^0=7 => 7.
  // Path for node 1: {0,1} -> max XOR with 15: 15^1=14,15^0=15 => 15.
  std::vector<int> expected = {3, 7, 15};
  std::vector<int> actual = solution_.getSolution()(parents, queries);
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumGeneticDifferenceQueryTestSuite,
    MaximumGeneticDifferenceQueryTest,
    ::testing::ValuesIn(MaximumGeneticDifferenceQuerySolution().getStrategyNames()));

}  // namespace problem_1938
}  // namespace leetcode
