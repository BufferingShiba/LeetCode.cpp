#include <gtest/gtest.h>

#include "leetcode/problems/minimum-absolute-difference-between-two-values.h"
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3880 {
namespace {

using TestParam = std::pair<std::string, std::vector<int>>;

class MinimumAbsoluteDifferenceBetweenTwoValuesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumAbsoluteDifferenceBetweenTwoValuesSolution solution;
};

TEST_P(MinimumAbsoluteDifferenceBetweenTwoValuesTest, Example1) {
  std::vector<int> nums{1, 0, 0, 2, 0, 1};
  EXPECT_EQ(2, solution.minAbsoluteDifference(nums));
}

TEST_P(MinimumAbsoluteDifferenceBetweenTwoValuesTest, Example2) {
  std::vector<int> nums{1, 0, 1, 0};
  EXPECT_EQ(-1, solution.minAbsoluteDifference(nums));
}

TEST_P(MinimumAbsoluteDifferenceBetweenTwoValuesTest, SelfAuthoredEdgeCaseAdjacent) {
  std::vector<int> nums{1, 2};
  EXPECT_EQ(1, solution.minAbsoluteDifference(nums));
}

TEST_P(MinimumAbsoluteDifferenceBetweenTwoValuesTest, SelfAuthoredEdgeCaseReverse) {
  std::vector<int> nums{2, 0, 1};
  EXPECT_EQ(2, solution.minAbsoluteDifference(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumAbsoluteDifferenceBetweenTwoValuesTestSuite,
    MinimumAbsoluteDifferenceBetweenTwoValuesTest,
    ::testing::ValuesIn(
        MinimumAbsoluteDifferenceBetweenTwoValuesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3880
}  // namespace leetcode
