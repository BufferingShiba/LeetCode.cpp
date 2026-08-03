#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/move-zeroes.h"

namespace leetcode {
namespace problem_283 {

class MoveZeroesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MoveZeroesSolution solution_;
};

TEST_P(MoveZeroesTest, Example1) {
  std::vector<int> nums = {0, 1, 0, 3, 12};
  solution_.moveZeroes(nums);
  EXPECT_EQ(nums, (std::vector<int>{1, 3, 12, 0, 0}));
}

TEST_P(MoveZeroesTest, Example2) {
  std::vector<int> nums = {0};
  solution_.moveZeroes(nums);
  EXPECT_EQ(nums, (std::vector<int>{0}));
}

TEST_P(MoveZeroesTest, SelfAuthored_NoZeros) {
  std::vector<int> nums = {1, 2, 3};
  solution_.moveZeroes(nums);
  EXPECT_EQ(nums, (std::vector<int>{1, 2, 3}));
}

TEST_P(MoveZeroesTest, SelfAuthored_AllZeros) {
  std::vector<int> nums = {0, 0, 0};
  solution_.moveZeroes(nums);
  EXPECT_EQ(nums, (std::vector<int>{0, 0, 0}));
}

TEST_P(MoveZeroesTest, SelfAuthored_Mixed) {
  std::vector<int> nums = {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
  solution_.moveZeroes(nums);
  EXPECT_EQ(nums, (std::vector<int>{4, 2, 4, 3, 5, 1, 0, 0, 0, 0}));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MoveZeroesTest,
    ::testing::ValuesIn(MoveZeroesSolution().getStrategyNames()));

}  // namespace problem_283
}  // namespace leetcode
