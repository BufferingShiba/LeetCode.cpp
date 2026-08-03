#include <gtest/gtest.h>

#include "leetcode/problems/find-the-number-of-copy-arrays.h"

namespace leetcode {
namespace problem_3468 {
namespace {

class FindTheNumberOfCopyArraysTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheNumberOfCopyArraysSolution solution_;
};

TEST_P(FindTheNumberOfCopyArraysTest, Example1) {
  std::vector<int> original = {1, 2, 3, 4};
  std::vector<std::vector<int>> bounds = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  EXPECT_EQ(solution_.countArrays(original, bounds), 2);
}

TEST_P(FindTheNumberOfCopyArraysTest, Example2) {
  std::vector<int> original = {1, 2, 3, 4};
  std::vector<std::vector<int>> bounds = {{1, 10}, {2, 9}, {3, 8}, {4, 7}};
  EXPECT_EQ(solution_.countArrays(original, bounds), 4);
}

TEST_P(FindTheNumberOfCopyArraysTest, Example3) {
  std::vector<int> original = {1, 2, 1, 2};
  std::vector<std::vector<int>> bounds = {{1, 1}, {2, 3}, {3, 3}, {2, 3}};
  EXPECT_EQ(solution_.countArrays(original, bounds), 0);
}

TEST_P(FindTheNumberOfCopyArraysTest, SelfAuthoredSinglePossibleOffset) {
  std::vector<int> original = {5, 7, 9};
  std::vector<std::vector<int>> bounds = {{6, 6}, {8, 8}, {10, 10}};
  // d = 1 only
  EXPECT_EQ(solution_.countArrays(original, bounds), 1);
}

TEST_P(FindTheNumberOfCopyArraysTest, SelfAuthoredLargeRange) {
  std::vector<int> original = {10, 20, 30};
  std::vector<std::vector<int>> bounds = {{1, 100}, {1, 100}, {1, 100}};
  // d in [-9, 90] for i=0, [-19, 80] for i=1, [-29, 70] for i=2
  // intersection: [-9, 70] → 80 values
  // Actually let's recalc:
  // i=0: 1-10=-9, 100-10=90 → [-9, 90]
  // i=1: 1-20=-19, 100-20=80 → [-19, 80]
  // i=2: 1-30=-29, 100-30=70 → [-29, 70]
  // d_min = max(-9,-19,-29) = -9, d_max = min(90,80,70) = 70
  // ans = 70 - (-9) + 1 = 80
  EXPECT_EQ(solution_.countArrays(original, bounds), 80);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheNumberOfCopyArraysTest,
    testing::ValuesIn(
        FindTheNumberOfCopyArraysSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3468
}  // namespace leetcode
