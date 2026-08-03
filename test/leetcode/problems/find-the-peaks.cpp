#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-peaks.h"

namespace leetcode::problem_2951 {

class FindThePeaksTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindThePeaksSolution solution;
};

TEST_P(FindThePeaksTest, Example1) {
  std::vector<int> mountain{2, 4, 4};
  std::vector<int> expected{};
  EXPECT_EQ(solution.findPeaks(mountain), expected);
}

TEST_P(FindThePeaksTest, Example2) {
  std::vector<int> mountain{1, 4, 3, 8, 5};
  std::vector<int> expected{1, 3};
  EXPECT_EQ(solution.findPeaks(mountain), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindThePeaksTestCases, FindThePeaksTest,
    ::testing::ValuesIn(FindThePeaksSolution().getStrategyNames()));

}  // namespace leetcode::problem_2951
