#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/count-array-pairs-divisible-by-k.h"

using namespace leetcode::problem_2183;

class CountArrayPairsDivisibleByKTest : public testing::TestWithParam<std::string> {
 protected:
  CountArrayPairsDivisibleByKSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CountArrayPairsDivisibleByKTest, Examples) {
  struct TestCase {
    std::vector<int> nums;
    int k;
    long long expected;
  };

  std::vector<TestCase> cases = {
      {{1, 2, 3, 4, 5}, 2, 7},
      {{1, 2, 3, 4}, 5, 0},
  };

  for (const auto& tc : cases) {
    auto nums = tc.nums;
    EXPECT_EQ(solution.countPairs(nums, tc.k), tc.expected);
  }
}

TEST_P(CountArrayPairsDivisibleByKTest, SelfAuthored) {
  // k=1: every product is divisible by 1, all C(n,2) pairs count
  {
    std::vector<int> nums = {1, 2, 3};
    // pairs: (0,1)=2, (0,2)=3, (1,2)=6 → all 3 divisible by 1
    EXPECT_EQ(solution.countPairs(nums, 1), 3);
  }
  // k larger than all elements, no pairs
  {
    std::vector<int> nums = {2, 3, 5};
    EXPECT_EQ(solution.countPairs(nums, 30), 0);
  }
  // single element: no pairs
  {
    std::vector<int> nums = {10};
    EXPECT_EQ(solution.countPairs(nums, 5), 0);
  }
  // all elements equal to k
  {
    std::vector<int> nums = {6, 6, 6};
    // all 3 pairs: 36 divisible by 6 ✓
    EXPECT_EQ(solution.countPairs(nums, 6), 3);
  }
  // mix: k=6, nums = [2,3,6,4]
  // gcds: 2,3,6,2. need: 3,2,1,3
  // i=0 (2): need 3, cnt[3]=0, update cnt[2]++. ans=0
  // i=1 (3): need 2, cnt[2]=1, ans=1, update cnt[3]++. ans=1
  // i=2 (6): need 1, cnt[1]=0, ans=1, update cnt[1,2,3,6]++. ans=1
  // i=3 (4): need 3, cnt[3]=1, ans=2, update cnt[2]++. ans=2
  // pairs: (2,3)=6✓, (2,6)=12✓, (3,6)=18✓, (2,4)=8✗, (3,4)=12✓, (6,4)=24✓ → 5
  {
    std::vector<int> nums = {2, 3, 6, 4};
    EXPECT_EQ(solution.countPairs(nums, 6), 5);
  }
}

INSTANTIATE_TEST_SUITE_P(Strategies, CountArrayPairsDivisibleByKTest,
                         testing::ValuesIn(CountArrayPairsDivisibleByKSolution()
                                               .getStrategyNames()));
