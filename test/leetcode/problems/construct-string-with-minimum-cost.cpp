#include "leetcode/problems/construct-string-with-minimum-cost.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3213 {

class ConstructStringWithMinimumCostTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ConstructStringWithMinimumCostSolution solution;
};

TEST_P(ConstructStringWithMinimumCostTest, Example1) {
  std::string target = "abcdef";
  std::vector<std::string> words = {"abdef", "abc", "d", "def", "ef"};
  std::vector<int> costs = {100, 1, 1, 10, 5};
  EXPECT_EQ(7, solution.getSolution()(target, words, costs));
}

TEST_P(ConstructStringWithMinimumCostTest, Example2Impossible) {
  std::string target = "aaaa";
  std::vector<std::string> words = {"z", "zz", "zzz"};
  std::vector<int> costs = {1, 10, 100};
  EXPECT_EQ(-1, solution.getSolution()(target, words, costs));
}

TEST_P(ConstructStringWithMinimumCostTest, SelfAuthoredSingleChar) {
  std::string target = "a";
  std::vector<std::string> words = {"a", "b"};
  std::vector<int> costs = {5, 3};
  EXPECT_EQ(5, solution.getSolution()(target, words, costs));
}

TEST_P(ConstructStringWithMinimumCostTest, SelfAuthoredDuplicateWordsTakeMinCost) {
  std::string target = "ab";
  std::vector<std::string> words = {"ab", "ab", "ab"};
  std::vector<int> costs = {10, 3, 7};
  EXPECT_EQ(3, solution.getSolution()(target, words, costs));
}

INSTANTIATE_TEST_SUITE_P(
    ConstructStringWithMinimumCostTestSuite,
    ConstructStringWithMinimumCostTest,
    ::testing::ValuesIn(ConstructStringWithMinimumCostSolution().getStrategyNames()));

}  // namespace problem_3213
}  // namespace leetcode
