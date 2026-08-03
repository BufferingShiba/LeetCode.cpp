#include "leetcode/problems/count-nice-pairs-in-an-array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1814 {
namespace {

std::vector<int> makeNums(std::initializer_list<int> vals) {
  return std::vector<int>(vals);
}

}  // namespace

class CountNicePairsInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountNicePairsInAnArraySolution solution;
};

TEST_P(CountNicePairsInAnArrayTest, Example1) {
  auto nums = makeNums({42, 11, 1, 97});
  EXPECT_EQ(solution.countNicePairs(nums), 2);
}

TEST_P(CountNicePairsInAnArrayTest, Example2) {
  auto nums = makeNums({13, 10, 35, 24, 76});
  EXPECT_EQ(solution.countNicePairs(nums), 4);
}

TEST_P(CountNicePairsInAnArrayTest, SelfAuthoredSingleElement) {
  auto nums = makeNums({5});
  EXPECT_EQ(solution.countNicePairs(nums), 0);
}

TEST_P(CountNicePairsInAnArrayTest, SelfAuthoredSingleDigitIdentical) {
  auto nums = makeNums({7, 7, 7});
  // x = n - rev(n) = 0 for all; pairs = C(3,2) = 3
  EXPECT_EQ(solution.countNicePairs(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    CountNicePairsInAnArrayTests, CountNicePairsInAnArrayTest,
    ::testing::ValuesIn(
        CountNicePairsInAnArraySolution().getStrategyNames()));

}  // namespace problem_1814
}  // namespace leetcode
