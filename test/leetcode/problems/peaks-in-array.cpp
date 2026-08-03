#include <gtest/gtest.h>

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "leetcode/problems/peaks-in-array.h"

namespace leetcode {
namespace problem_3187 {

class PeaksInArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PeaksInArraySolution solution;
};

TEST_P(PeaksInArrayTest, Example1) {
  vector<int> nums = {3, 1, 4, 2, 5};
  vector<vector<int>> queries = {{2, 3, 4}, {1, 0, 4}};
  vector<int> expected = {0};
  EXPECT_EQ(expected, solution.countOfPeaks(nums, queries));
}

TEST_P(PeaksInArrayTest, Example2) {
  vector<int> nums = {4, 1, 4, 2, 1, 5};
  vector<vector<int>> queries = {{2, 2, 4}, {1, 0, 2}, {1, 0, 4}};
  vector<int> expected = {0, 1};
  EXPECT_EQ(expected, solution.countOfPeaks(nums, queries));
}

INSTANTIATE_TEST_SUITE_P(PeaksInArrayTestSuite, PeaksInArrayTest,
                         ::testing::ValuesIn(PeaksInArraySolution().getStrategyNames()));

}  // namespace problem_3187
}  // namespace leetcode
