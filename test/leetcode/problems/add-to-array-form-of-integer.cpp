#include "leetcode/problems/add-to-array-form-of-integer.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_989 {
namespace {

using TestParam = std::tuple<std::vector<int>, int, std::vector<int>>;

class AddToArrayFormOfIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  AddToArrayFormOfIntegerSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(AddToArrayFormOfIntegerTest, Example1) {
  std::vector<int> num{1, 2, 0, 0};
  std::vector<int> expected{1, 2, 3, 4};
  EXPECT_EQ(solution.addToArrayForm(num, 34), expected);
}

TEST_P(AddToArrayFormOfIntegerTest, Example2) {
  std::vector<int> num{2, 7, 4};
  std::vector<int> expected{4, 5, 5};
  EXPECT_EQ(solution.addToArrayForm(num, 181), expected);
}

TEST_P(AddToArrayFormOfIntegerTest, Example3) {
  std::vector<int> num{2, 1, 5};
  std::vector<int> expected{1, 0, 2, 1};
  EXPECT_EQ(solution.addToArrayForm(num, 806), expected);
}

TEST_P(AddToArrayFormOfIntegerTest, SelfAuthoredCarryPropagation) {
  std::vector<int> num{9, 9, 9};
  std::vector<int> expected{1, 0, 0, 0};
  EXPECT_EQ(solution.addToArrayForm(num, 1), expected);
}

TEST_P(AddToArrayFormOfIntegerTest, SelfAuthoredZeroValueInNum) {
  std::vector<int> num{0};
  std::vector<int> expected{9};
  EXPECT_EQ(solution.addToArrayForm(num, 9), expected);
}

INSTANTIATE_TEST_SUITE_P(
    AddToArrayFormOfIntegerTestCases, AddToArrayFormOfIntegerTest,
    ::testing::ValuesIn(AddToArrayFormOfIntegerSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_989
}  // namespace leetcode
