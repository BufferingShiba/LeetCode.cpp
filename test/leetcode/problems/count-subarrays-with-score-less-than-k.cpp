#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/count-subarrays-with-score-less-than-k.h"

namespace leetcode::problem_2302 {

class CountSubarraysWithScoreLessThanKTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CountSubarraysWithScoreLessThanKSolution solution;
};

TEST_P(CountSubarraysWithScoreLessThanKTest, OfficialExamples) {
  // Example 1
  {
    std::vector<int> nums = {2, 1, 4, 3, 5};
    long long k = 10;
    EXPECT_EQ(solution.countSubarrays(nums, k), 6);
  }

  // Example 2
  {
    std::vector<int> nums = {1, 1, 1};
    long long k = 5;
    EXPECT_EQ(solution.countSubarrays(nums, k), 5);
  }
}

TEST_P(CountSubarraysWithScoreLessThanKTest, SelfAuthored) {
  // Single element less than k
  {
    std::vector<int> nums = {7};
    long long k = 8;
    EXPECT_EQ(solution.countSubarrays(nums, k), 1);  // [7]: 7*1=7 < 8
  }

  // Single element equal to k (score == k, not counted)
  {
    std::vector<int> nums = {8};
    long long k = 8;
    EXPECT_EQ(solution.countSubarrays(nums, k), 0);  // [8]: 8*1=8 not < 8
  }

  // All subarrays valid
  {
    std::vector<int> nums = {1, 2};
    long long k = 100;
    // [1]=1, [2]=2, [1,2]=(3)*2=6 → all 3
    EXPECT_EQ(solution.countSubarrays(nums, k), 3);
  }

  // Large k, all subarrays valid
  {
    std::vector<int> nums = {1, 2, 3};
    long long k = 100;
    // 6 subarrays total: [1]=1,[2]=2,[3]=3,[1,2]=6,[2,3]=10,[1,2,3]=18
    EXPECT_EQ(solution.countSubarrays(nums, k), 6);
  }

  // Tight constraint: only length-1 subarrays valid
  {
    std::vector<int> nums = {1, 2, 3};
    long long k = 4;
    // [1]=1<4, [2]=2<4, [3]=3<4, [1,2]=(3)*2=6>=4, [2,3]=5*2=10>=4, [1,2,3]=6*3=18>=4
    EXPECT_EQ(solution.countSubarrays(nums, k), 3);
  }
}

INSTANTIATE_TEST_SUITE_P(Strategies, CountSubarraysWithScoreLessThanKTest,
                         ::testing::ValuesIn(
                             CountSubarraysWithScoreLessThanKSolution().getStrategyNames()));

}  // namespace leetcode::problem_2302
