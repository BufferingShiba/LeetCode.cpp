#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/relative-sort-array.h"

namespace leetcode {
namespace problem_1122 {

class RelativeSortArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  RelativeSortArraySolution solution;
};

TEST_P(RelativeSortArrayTest, Example1) {
  std::vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
  std::vector<int> arr2 = {2, 1, 4, 3, 9, 6};
  std::vector<int> expected = {2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19};
  EXPECT_EQ(solution.relativeSortArray(arr1, arr2), expected);
}

TEST_P(RelativeSortArrayTest, Example2) {
  std::vector<int> arr1 = {28, 6, 22, 8, 44, 17};
  std::vector<int> arr2 = {22, 28, 8, 6};
  std::vector<int> expected = {22, 28, 8, 6, 17, 44};
  EXPECT_EQ(solution.relativeSortArray(arr1, arr2), expected);
}

TEST_P(RelativeSortArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> arr1 = {5};
  std::vector<int> arr2 = {5};
  std::vector<int> expected = {5};
  EXPECT_EQ(solution.relativeSortArray(arr1, arr2), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RelativeSortArrayTestSuite, RelativeSortArrayTest,
    ::testing::ValuesIn(RelativeSortArraySolution().getStrategyNames()));

}  // namespace problem_1122
}  // namespace leetcode
