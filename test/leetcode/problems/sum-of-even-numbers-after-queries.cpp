#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "leetcode/problems/sum-of-even-numbers-after-queries.h"

namespace leetcode {
namespace problem_985 {
namespace {

using SumOfEvenNumbersAfterQueriesTest =
    ::testing::TestWithParam<std::string>;

INSTANTIATE_TEST_SUITE_P(
    SumOfEvenNumbersAfterQueriesStrategies, SumOfEvenNumbersAfterQueriesTest,
    ::testing::ValuesIn(SumOfEvenNumbersAfterQueriesSolution().getStrategyNames()));

}  // namespace

TEST_P(SumOfEvenNumbersAfterQueriesTest, Example1) {
  SumOfEvenNumbersAfterQueriesSolution solution;
  solution.setStrategy(GetParam());

  std::vector<int> nums{1, 2, 3, 4};
  std::vector<std::vector<int>> queries{{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
  std::vector<int> expected{8, 6, 2, 4};
  EXPECT_EQ(solution.sumEvenAfterQueries(nums, queries), expected);
}

TEST_P(SumOfEvenNumbersAfterQueriesTest, Example2) {
  SumOfEvenNumbersAfterQueriesSolution solution;
  solution.setStrategy(GetParam());

  std::vector<int> nums{1};
  std::vector<std::vector<int>> queries{{4, 0}};
  std::vector<int> expected{0};
  EXPECT_EQ(solution.sumEvenAfterQueries(nums, queries), expected);
}

TEST_P(SumOfEvenNumbersAfterQueriesTest, AllEvenInitially) {
  SumOfEvenNumbersAfterQueriesSolution solution;
  solution.setStrategy(GetParam());

  std::vector<int> nums{2, 4, 6};
  std::vector<std::vector<int>> queries{{1, 0}, {3, 2}, {-2, 1}};
  // Initial sum = 12.
  // q0 (1,0): nums[0]=2 even -> sum=12-2=10; +1=3 odd; ans=10
  // q1 (3,2): nums[2]=6 even -> sum=10-6=4; +3=9 odd; ans=4
  // q2 (-2,1): nums[1]=4 even -> sum=4-4=0; -2=2 even; sum=0+2=2; ans=2
  std::vector<int> expected{10, 4, 2};
  EXPECT_EQ(solution.sumEvenAfterQueries(nums, queries), expected);
}

TEST_P(SumOfEvenNumbersAfterQueriesTest, AllOddInitially) {
  SumOfEvenNumbersAfterQueriesSolution solution;
  solution.setStrategy(GetParam());

  std::vector<int> nums{1, 3, 5};
  std::vector<std::vector<int>> queries{{1, 0}};
  // nums[0]=1 -> 2 (even), sum=2
  std::vector<int> expected{2};
  EXPECT_EQ(solution.sumEvenAfterQueries(nums, queries), expected);
}

}  // namespace problem_985
}  // namespace leetcode
