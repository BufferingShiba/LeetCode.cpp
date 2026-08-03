#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/triples-with-bitwise-and-equal-to-zero.h"

namespace leetcode {
namespace problem_982 {
namespace {

class TriplesWithBitwiseAndEqualToZeroTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TriplesWithBitwiseAndEqualToZeroSolution solution_;
};

TEST_P(TriplesWithBitwiseAndEqualToZeroTest, Example1) {
  std::vector<int> nums{2, 1, 3};
  EXPECT_EQ(solution_.countTriplets(nums), 12);
}

TEST_P(TriplesWithBitwiseAndEqualToZeroTest, Example2) {
  std::vector<int> nums{0, 0, 0};
  EXPECT_EQ(solution_.countTriplets(nums), 27);
}

TEST_P(TriplesWithBitwiseAndEqualToZeroTest, SelfAuthoredSingleElementZero) {
  std::vector<int> nums{0};
  EXPECT_EQ(solution_.countTriplets(nums), 1);
}

TEST_P(TriplesWithBitwiseAndEqualToZeroTest, SelfAuthoredSingleElementNonZero) {
  std::vector<int> nums{5};
  EXPECT_EQ(solution_.countTriplets(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    TriplesWithBitwiseAndEqualToZeroTestCases,
    TriplesWithBitwiseAndEqualToZeroTest,
    ::testing::ValuesIn(TriplesWithBitwiseAndEqualToZeroSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_982
}  // namespace leetcode
