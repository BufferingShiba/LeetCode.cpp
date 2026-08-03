
#include "leetcode/problems/valid-mountain-array.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_941 {

class ValidMountainArrayTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidMountainArraySolution solution;
};

TEST_P(ValidMountainArrayTest, Example1) {
  vector<int> arr = {2, 1};
  EXPECT_FALSE(solution.validMountainArray(arr));
}

TEST_P(ValidMountainArrayTest, Example2) {
  vector<int> arr = {3, 5, 5};
  EXPECT_FALSE(solution.validMountainArray(arr));
}

TEST_P(ValidMountainArrayTest, Example3) {
  vector<int> arr = {0, 3, 2, 1};
  EXPECT_TRUE(solution.validMountainArray(arr));
}

TEST_P(ValidMountainArrayTest, SelfAuthoredStrictlyIncreasing) {
  vector<int> arr = {1, 2, 3, 4};
  EXPECT_FALSE(solution.validMountainArray(arr));
}

TEST_P(ValidMountainArrayTest, SelfAuthoredStrictlyDecreasing) {
  vector<int> arr = {4, 3, 2, 1};
  EXPECT_FALSE(solution.validMountainArray(arr));
}

TEST_P(ValidMountainArrayTest, SelfAuthoredSingleElement) {
  vector<int> arr = {5};
  EXPECT_FALSE(solution.validMountainArray(arr));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, ValidMountainArrayTest,
    ::testing::ValuesIn(ValidMountainArraySolution().getStrategyNames()));

}  // namespace problem_941
}  // namespace leetcode
