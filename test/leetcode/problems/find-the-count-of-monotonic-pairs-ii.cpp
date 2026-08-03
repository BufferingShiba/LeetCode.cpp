#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-count-of-monotonic-pairs-ii.h"

namespace leetcode {
namespace problem_3251 {
namespace {

class FindTheCountOfMonotonicPairsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindTheCountOfMonotonicPairsIiSolution solution;
};

TEST_P(FindTheCountOfMonotonicPairsIiTest, Example1) {
  std::vector<int> nums = {2, 3, 2};
  EXPECT_EQ(4, solution.countOfPairs(nums));
}

TEST_P(FindTheCountOfMonotonicPairsIiTest, Example2) {
  std::vector<int> nums = {5, 5, 5, 5};
  EXPECT_EQ(126, solution.countOfPairs(nums));
}

TEST_P(FindTheCountOfMonotonicPairsIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {3};
  // arr1[0] in [0,3], arr2[0]=3-arr1[0]; any single value is valid.
  EXPECT_EQ(4, solution.countOfPairs(nums));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FindTheCountOfMonotonicPairsIiTest,
    ::testing::ValuesIn(
        FindTheCountOfMonotonicPairsIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3251
}  // namespace leetcode
