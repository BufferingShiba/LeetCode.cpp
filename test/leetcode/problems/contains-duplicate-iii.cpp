#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/contains-duplicate-iii.h"

namespace leetcode {
namespace problem_220 {

class ContainsDuplicateIiiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ContainsDuplicateIiiSolution solution_;
};

TEST_P(ContainsDuplicateIiiTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 1};
  int indexDiff = 3;
  int valueDiff = 0;
  EXPECT_TRUE(solution_.containsNearbyAlmostDuplicate(nums, indexDiff,
                                                      valueDiff));
}

TEST_P(ContainsDuplicateIiiTest, Example2) {
  std::vector<int> nums = {1, 5, 9, 1, 5, 9};
  int indexDiff = 2;
  int valueDiff = 3;
  EXPECT_FALSE(solution_.containsNearbyAlmostDuplicate(nums, indexDiff,
                                                       valueDiff));
}

TEST_P(ContainsDuplicateIiiTest, SelfAuthored_NegativeNumbers) {
  std::vector<int> nums = {-3, 0, -3, 4};
  int indexDiff = 2;
  int valueDiff = 2;
  // |(-3) - (-3)| = 0 <= 2, indices 0 and 2, |0-2|=2 <= 2
  EXPECT_TRUE(solution_.containsNearbyAlmostDuplicate(nums, indexDiff,
                                                      valueDiff));
}

TEST_P(ContainsDuplicateIiiTest, SelfAuthored_AdjacentBuckets) {
  std::vector<int> nums = {1, 3, 6, 2};
  int indexDiff = 3;
  int valueDiff = 1;
  // 1 and 2: |1-2|=1 <= 1, indices 0 and 3, |0-3|=3 <= 3
  EXPECT_TRUE(solution_.containsNearbyAlmostDuplicate(nums, indexDiff,
                                                      valueDiff));
}

TEST_P(ContainsDuplicateIiiTest, SelfAuthored_NoPair) {
  std::vector<int> nums = {1, 10, 20, 30};
  int indexDiff = 2;
  int valueDiff = 5;
  EXPECT_FALSE(solution_.containsNearbyAlmostDuplicate(nums, indexDiff,
                                                       valueDiff));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ContainsDuplicateIiiTest,
    testing::ValuesIn(ContainsDuplicateIiiSolution().getStrategyNames()));

}  // namespace problem_220
}  // namespace leetcode
