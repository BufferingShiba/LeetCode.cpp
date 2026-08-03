#include <gtest/gtest.h>
#include "leetcode/problems/check-if-all-1s-are-at-least-length-k-places-away.h"

namespace leetcode {
namespace problem_1437 {
namespace {

class CheckIfAll1sAreAtLeastLengthKPlacesAwayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution solution;
};

TEST_P(CheckIfAll1sAreAtLeastLengthKPlacesAwayTest, Example1) {
  std::vector<int> nums = {1, 0, 0, 0, 1, 0, 0, 1};
  int k = 2;
  EXPECT_TRUE(solution.kLengthApart(nums, k));
}

TEST_P(CheckIfAll1sAreAtLeastLengthKPlacesAwayTest, Example2) {
  std::vector<int> nums = {1, 0, 0, 1, 0, 1};
  int k = 2;
  EXPECT_FALSE(solution.kLengthApart(nums, k));
}

TEST_P(CheckIfAll1sAreAtLeastLengthKPlacesAwayTest, SelfAuthoredSingleOne) {
  std::vector<int> nums = {0, 0, 1, 0, 0};
  int k = 1;
  EXPECT_TRUE(solution.kLengthApart(nums, k));
}

TEST_P(CheckIfAll1sAreAtLeastLengthKPlacesAwayTest, SelfAuthoredKEqualsZero) {
  std::vector<int> nums = {1, 1, 1};
  int k = 0;
  EXPECT_TRUE(solution.kLengthApart(nums, k));
}

TEST_P(CheckIfAll1sAreAtLeastLengthKPlacesAwayTest, SelfAuthoredAdjacentOnesWithK1) {
  std::vector<int> nums = {1, 0, 1};
  int k = 1;
  EXPECT_TRUE(solution.kLengthApart(nums, k));
}

TEST_P(CheckIfAll1sAreAtLeastLengthKPlacesAwayTest, SelfAuthoredAdjacentOnesWithK2) {
  std::vector<int> nums = {1, 0, 1};
  int k = 2;
  EXPECT_FALSE(solution.kLengthApart(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfAll1sAreAtLeastLengthKPlacesAwayTest,
    testing::ValuesIn(
        CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1437
}  // namespace leetcode
