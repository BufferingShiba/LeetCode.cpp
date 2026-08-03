#include "leetcode/problems/partition-array-into-k-distinct-groups.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3659 {

class PartitionArrayIntoKDistinctGroupsTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PartitionArrayIntoKDistinctGroupsSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [1,2,3,4], k = 2
// Output: true
TEST_P(PartitionArrayIntoKDistinctGroupsTest, OfficialExample1) {
  vector<int> nums = {1, 2, 3, 4};
  int k = 2;
  EXPECT_EQ(true, solution.partitionArray(nums, k));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [3,5,2,2], k = 2
// Output: true
TEST_P(PartitionArrayIntoKDistinctGroupsTest, OfficialExample2) {
  vector<int> nums = {3, 5, 2, 2};
  int k = 2;
  EXPECT_EQ(true, solution.partitionArray(nums, k));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  nums = [1,5,2,3], k = 3
// Output: false
TEST_P(PartitionArrayIntoKDistinctGroupsTest, OfficialExample3) {
  vector<int> nums = {1, 5, 2, 3};
  int k = 3;
  EXPECT_EQ(false, solution.partitionArray(nums, k));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, PartitionArrayIntoKDistinctGroupsTest,
    ::testing::ValuesIn(PartitionArrayIntoKDistinctGroupsSolution().getStrategyNames()));

}  // namespace problem_3659
}  // namespace leetcode
