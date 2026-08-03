#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/duplicate-zeros.h"

namespace leetcode {
namespace problem_1089 {

class DuplicateZerosTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DuplicateZerosSolution solution;
};

TEST_P(DuplicateZerosTest, Example1) {
  std::vector<int> arr{1, 0, 2, 3, 0, 4, 5, 0};
  std::vector<int> expected{1, 0, 0, 2, 3, 0, 0, 4};
  solution.duplicateZeros(arr);
  EXPECT_EQ(arr, expected);
}

TEST_P(DuplicateZerosTest, Example2) {
  std::vector<int> arr{1, 2, 3};
  std::vector<int> expected{1, 2, 3};
  solution.duplicateZeros(arr);
  EXPECT_EQ(arr, expected);
}

TEST_P(DuplicateZerosTest, SelfAuthoredAllZeros) {
  std::vector<int> arr{0, 0, 0, 0};
  std::vector<int> expected{0, 0, 0, 0};
  solution.duplicateZeros(arr);
  EXPECT_EQ(arr, expected);
}

TEST_P(DuplicateZerosTest, SelfAuthoredSingleZero) {
  std::vector<int> arr{0};
  std::vector<int> expected{0};
  solution.duplicateZeros(arr);
  EXPECT_EQ(arr, expected);
}

TEST_P(DuplicateZerosTest, LastZeroIsCopiedOnlyOnce) {
  std::vector<int> arr{8, 4, 5, 0, 0, 0, 0, 7};
  std::vector<int> expected{8, 4, 5, 0, 0, 0, 0, 0};
  solution.duplicateZeros(arr);
  EXPECT_EQ(arr, expected);
}

INSTANTIATE_TEST_SUITE_P(
    DuplicateZerosTestSuite, DuplicateZerosTest,
    ::testing::ValuesIn(DuplicateZerosSolution().getStrategyNames()));

}  // namespace problem_1089
}  // namespace leetcode
