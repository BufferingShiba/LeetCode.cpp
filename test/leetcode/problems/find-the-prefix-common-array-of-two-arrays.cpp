#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-prefix-common-array-of-two-arrays.h"

namespace leetcode {
namespace problem_2657 {
namespace {

class FindThePrefixCommonArrayOfTwoArraysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindThePrefixCommonArrayOfTwoArraysSolution solution_;
};

TEST_P(FindThePrefixCommonArrayOfTwoArraysTest, Example1) {
  std::vector<int> A{1, 3, 2, 4};
  std::vector<int> B{3, 1, 2, 4};
  std::vector<int> expected{0, 2, 3, 4};
  EXPECT_EQ(expected, solution_.findThePrefixCommonArray(A, B));
}

TEST_P(FindThePrefixCommonArrayOfTwoArraysTest, Example2) {
  std::vector<int> A{2, 3, 1};
  std::vector<int> B{3, 1, 2};
  std::vector<int> expected{0, 1, 3};
  EXPECT_EQ(expected, solution_.findThePrefixCommonArray(A, B));
}

TEST_P(FindThePrefixCommonArrayOfTwoArraysTest, SelfAuthoredSingle) {
  std::vector<int> A{1};
  std::vector<int> B{1};
  std::vector<int> expected{1};
  EXPECT_EQ(expected, solution_.findThePrefixCommonArray(A, B));
}

TEST_P(FindThePrefixCommonArrayOfTwoArraysTest, SelfAuthoredSameOrder) {
  std::vector<int> A{1, 2, 3, 4};
  std::vector<int> B{1, 2, 3, 4};
  std::vector<int> expected{1, 2, 3, 4};
  EXPECT_EQ(expected, solution_.findThePrefixCommonArray(A, B));
}

INSTANTIATE_TEST_SUITE_P(
    FindThePrefixCommonArrayOfTwoArraysTest, FindThePrefixCommonArrayOfTwoArraysTest,
    ::testing::ValuesIn(
        FindThePrefixCommonArrayOfTwoArraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2657
}  // namespace leetcode
