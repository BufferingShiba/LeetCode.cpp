#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-array-is-good.h"

namespace leetcode {
namespace problem_2784 {

class CheckIfArrayIsGoodTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CheckIfArrayIsGoodSolution solution_;
};

TEST_P(CheckIfArrayIsGoodTest, Example1) {
  std::vector<int> nums = {2, 1, 3};
  EXPECT_FALSE(solution_.isGood(nums));
}

TEST_P(CheckIfArrayIsGoodTest, Example2) {
  std::vector<int> nums = {1, 3, 3, 2};
  EXPECT_TRUE(solution_.isGood(nums));
}

TEST_P(CheckIfArrayIsGoodTest, Example3) {
  std::vector<int> nums = {1, 1};
  EXPECT_TRUE(solution_.isGood(nums));
}

TEST_P(CheckIfArrayIsGoodTest, Example4) {
  std::vector<int> nums = {3, 4, 4, 1, 2, 1};
  EXPECT_FALSE(solution_.isGood(nums));
}

TEST_P(CheckIfArrayIsGoodTest, SelfAuthored) {
  // base[2] = [1, 2, 2] -> true
  {
    std::vector<int> nums = {2, 1, 2};
    EXPECT_TRUE(solution_.isGood(nums));
  }

  // All same elements -> false
  {
    std::vector<int> nums = {5, 5, 5, 5, 5, 5};
    EXPECT_FALSE(solution_.isGood(nums));
  }

  // Length matches n+1 but missing 1
  {
    std::vector<int> nums = {2, 3, 3};
    EXPECT_FALSE(solution_.isGood(nums));
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfArrayIsGoodTest,
    ::testing::ValuesIn(CheckIfArrayIsGoodSolution().getStrategyNames()));

}  // namespace problem_2784
}  // namespace leetcode
