#include <gtest/gtest.h>

#include "leetcode/problems/adjacent-increasing-subarrays-detection-i.h"

namespace leetcode {
namespace problem_3349 {

class AdjacentIncreasingSubarraysDetectionITest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  AdjacentIncreasingSubarraysDetectionISolution solution_;
};

TEST_P(AdjacentIncreasingSubarraysDetectionITest, Example1) {
  std::vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
  int k = 3;
  EXPECT_TRUE(solution_.hasIncreasingSubarrays(nums, k));
}

TEST_P(AdjacentIncreasingSubarraysDetectionITest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
  int k = 5;
  EXPECT_FALSE(solution_.hasIncreasingSubarrays(nums, k));
}

TEST_P(AdjacentIncreasingSubarraysDetectionITest, MinimalTrue) {
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 2;
  // [1,2] and [3,4] are both strictly increasing and adjacent
  EXPECT_TRUE(solution_.hasIncreasingSubarrays(nums, k));
}

TEST_P(AdjacentIncreasingSubarraysDetectionITest, NoAdjacentPair) {
  std::vector<int> nums = {3, 1, 4, 2};
  int k = 2;
  // inc[0]=false ([3,1]), inc[1]=true ([1,4]), inc[2]=false ([4,2])
  // No i with inc[i] && inc[i+2] both true
  EXPECT_FALSE(solution_.hasIncreasingSubarrays(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    AdjacentIncreasingSubarraysDetectionITest,
    ::testing::ValuesIn(AdjacentIncreasingSubarraysDetectionISolution().getStrategyNames()));

}  // namespace problem_3349
}  // namespace leetcode
