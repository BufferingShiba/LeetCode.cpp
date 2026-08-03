#include <gtest/gtest.h>

#include "leetcode/problems/number-of-unique-xor-triplets-ii.h"

namespace leetcode::problem_3514 {

class NumberOfUniqueXorTripletsIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfUniqueXorTripletsIiSolution solution;
};

TEST_P(NumberOfUniqueXorTripletsIiTest, Example1) {
  std::vector<int> nums = {1, 3};
  EXPECT_EQ(solution.uniqueXorTriplets(nums), 2);
}

TEST_P(NumberOfUniqueXorTripletsIiTest, Example2) {
  std::vector<int> nums = {6, 7, 8, 9};
  EXPECT_EQ(solution.uniqueXorTriplets(nums), 4);
}

TEST_P(NumberOfUniqueXorTripletsIiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_EQ(solution.uniqueXorTriplets(nums), 1);
}

TEST_P(NumberOfUniqueXorTripletsIiTest, SelfAuthoredTwoSameElements) {
  std::vector<int> nums = {4, 4};
  // 可能的三元组: (0,0,0)=4, (0,0,1)=4, (0,1,1)=4, (1,1,1)=4 -> only 4
  EXPECT_EQ(solution.uniqueXorTriplets(nums), 1);
}

TEST_P(NumberOfUniqueXorTripletsIiTest, SelfAuthoredThreeElements) {
  std::vector<int> nums = {1, 2, 3};
  // i<=j<=k: 可能值包括 1,2,3 以及 1^2^3=0
  EXPECT_EQ(solution.uniqueXorTriplets(nums), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfUniqueXorTripletsIiTest,
    ::testing::ValuesIn(NumberOfUniqueXorTripletsIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3514
