#include <gtest/gtest.h>

#include "leetcode/problems/find-the-n-th-value-after-k-seconds.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3179 {
namespace {

class FindTheNThValueAfterKSecondsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheNThValueAfterKSecondsSolution solution;
};

TEST_P(FindTheNThValueAfterKSecondsTest, Example1) {
  EXPECT_EQ(56, solution.valueAfterKSeconds(4, 5));
}

TEST_P(FindTheNThValueAfterKSecondsTest, Example2) {
  EXPECT_EQ(35, solution.valueAfterKSeconds(5, 3));
}

TEST_P(FindTheNThValueAfterKSecondsTest, SelfAuthoredSingleElement) {
  // a[0] stays 1 forever regardless of k.
  EXPECT_EQ(1, solution.valueAfterKSeconds(1, 1000));
}

TEST_P(FindTheNThValueAfterKSecondsTest, SelfAuthoredZeroSeconds) {
  // With k=0, all elements remain 1.
  EXPECT_EQ(1, solution.valueAfterKSeconds(7, 0));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheNThValueAfterKSecondsTestSuite,
    FindTheNThValueAfterKSecondsTest,
    ::testing::ValuesIn(
        FindTheNThValueAfterKSecondsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3179
}  // namespace leetcode
