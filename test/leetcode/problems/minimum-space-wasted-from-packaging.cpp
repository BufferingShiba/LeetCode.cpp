#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-space-wasted-from-packaging.h"

namespace leetcode {
namespace problem_1889 {
namespace {

class MinimumSpaceWastedFromPackagingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumSpaceWastedFromPackagingSolution solution;
};

TEST_P(MinimumSpaceWastedFromPackagingTest, Example1) {
  std::vector<int> packages = {2, 3, 5};
  std::vector<std::vector<int>> boxes = {{4, 8}, {2, 8}};
  EXPECT_EQ(6, solution.minWastedSpace(packages, boxes));
}

TEST_P(MinimumSpaceWastedFromPackagingTest, Example2) {
  std::vector<int> packages = {2, 3, 5};
  std::vector<std::vector<int>> boxes = {{1, 4}, {2, 3}, {3, 4}};
  EXPECT_EQ(-1, solution.minWastedSpace(packages, boxes));
}

TEST_P(MinimumSpaceWastedFromPackagingTest, Example3) {
  std::vector<int> packages = {3, 5, 8, 10, 11, 12};
  std::vector<std::vector<int>> boxes = {{12}, {11, 9}, {10, 5, 14}};
  EXPECT_EQ(9, solution.minWastedSpace(packages, boxes));
}

TEST_P(MinimumSpaceWastedFromPackagingTest, SelfAuthoredSinglePackage) {
  std::vector<int> packages = {5};
  std::vector<std::vector<int>> boxes = {{5}};
  EXPECT_EQ(0, solution.minWastedSpace(packages, boxes));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumSpaceWastedFromPackagingTestSuite,
    MinimumSpaceWastedFromPackagingTest,
    ::testing::ValuesIn(
        MinimumSpaceWastedFromPackagingSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1889
}  // namespace leetcode
