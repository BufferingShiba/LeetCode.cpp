#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/remove-duplicates-from-sorted-array.h"

namespace leetcode::problem_26 {

class RemoveDuplicatesFromSortedArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemoveDuplicatesFromSortedArray solution_;
};

TEST_P(RemoveDuplicatesFromSortedArrayTest, Example1) {
  std::vector<int> nums = {1, 1, 2};
  int k = solution_.removeDuplicates(nums);
  EXPECT_EQ(k, 2);
  EXPECT_EQ((std::vector<int>{nums.begin(), nums.begin() + k}), (std::vector<int>{1, 2}));
}

TEST_P(RemoveDuplicatesFromSortedArrayTest, Example2) {
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k = solution_.removeDuplicates(nums);
  EXPECT_EQ(k, 5);
  EXPECT_EQ((std::vector<int>{nums.begin(), nums.begin() + k}), (std::vector<int>{0, 1, 2, 3, 4}));
}

TEST_P(RemoveDuplicatesFromSortedArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  int k = solution_.removeDuplicates(nums);
  EXPECT_EQ(k, 1);
  EXPECT_EQ((std::vector<int>{nums.begin(), nums.begin() + k}), (std::vector<int>{42}));
}

TEST_P(RemoveDuplicatesFromSortedArrayTest, SelfAuthoredAllSame) {
  std::vector<int> nums = {7, 7, 7, 7};
  int k = solution_.removeDuplicates(nums);
  EXPECT_EQ(k, 1);
  EXPECT_EQ((std::vector<int>{nums.begin(), nums.begin() + k}), (std::vector<int>{7}));
}

TEST_P(RemoveDuplicatesFromSortedArrayTest, SelfAuthoredNoDuplicates) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int k = solution_.removeDuplicates(nums);
  EXPECT_EQ(k, 5);
  EXPECT_EQ((std::vector<int>{nums.begin(), nums.begin() + k}), (std::vector<int>{1, 2, 3, 4, 5}));
}

INSTANTIATE_TEST_SUITE_P(
    RemoveDuplicatesFromSortedArrayTestSuite,
    RemoveDuplicatesFromSortedArrayTest,
    ::testing::ValuesIn(RemoveDuplicatesFromSortedArray().getStrategyNames()));

}  // namespace leetcode::problem_26
