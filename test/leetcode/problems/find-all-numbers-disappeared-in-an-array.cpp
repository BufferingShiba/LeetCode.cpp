#include <gtest/gtest.h>

#include "leetcode/problems/find-all-numbers-disappeared-in-an-array.h"

namespace leetcode {
namespace problem_448 {
namespace {

class FindAllNumbersDisappearedInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FindAllNumbersDisappearedInAnArraySolution solution_;
};

TEST_P(FindAllNumbersDisappearedInAnArrayTest, Example1) {
  std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
  std::vector<int> expected{5, 6};
  EXPECT_EQ(solution_.findDisappearedNumbers(nums), expected);
}

TEST_P(FindAllNumbersDisappearedInAnArrayTest, Example2) {
  std::vector<int> nums{1, 1};
  std::vector<int> expected{2};
  EXPECT_EQ(solution_.findDisappearedNumbers(nums), expected);
}

TEST_P(FindAllNumbersDisappearedInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  std::vector<int> expected{};
  EXPECT_EQ(solution_.findDisappearedNumbers(nums), expected);
}

TEST_P(FindAllNumbersDisappearedInAnArrayTest, SelfAuthoredAllMissing) {
  std::vector<int> nums{3, 3, 3};
  std::vector<int> expected{1, 2};
  EXPECT_EQ(solution_.findDisappearedNumbers(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindAllNumbersDisappearedInAnArrayTestSuite,
    FindAllNumbersDisappearedInAnArrayTest,
    ::testing::ValuesIn(
        FindAllNumbersDisappearedInAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_448
}  // namespace leetcode
