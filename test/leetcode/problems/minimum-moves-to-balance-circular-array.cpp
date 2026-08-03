#include <gtest/gtest.h>

#include "leetcode/problems/minimum-moves-to-balance-circular-array.h"

namespace leetcode {
namespace problem_3776 {

class MinimumMovesToBalanceCircularArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumMovesToBalanceCircularArraySolution solution_;
};

TEST_P(MinimumMovesToBalanceCircularArrayTest, Example1) {
  std::vector<int> balance = {5, 1, -4};
  EXPECT_EQ(solution_.minMoves(balance), 4);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, Example2) {
  std::vector<int> balance = {1, 2, -5, 2};
  EXPECT_EQ(solution_.minMoves(balance), 6);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, Example3) {
  std::vector<int> balance = {-3, 2};
  EXPECT_EQ(solution_.minMoves(balance), -1);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredNoNegative) {
  std::vector<int> balance = {1, 2, 3};
  EXPECT_EQ(solution_.minMoves(balance), 0);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredSingleElementPositive) {
  std::vector<int> balance = {5};
  EXPECT_EQ(solution_.minMoves(balance), 0);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredSingleElementNegative) {
  std::vector<int> balance = {-5};
  EXPECT_EQ(solution_.minMoves(balance), -1);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredLargeDistances) {
  // n=6, negative at index 0, need 10.
  // Distances: i=1 d=1, i=2 d=2, i=3 d=3, i=4 d=2, i=5 d=1
  // Values: all 10, but we need only 10 from nearest.
  std::vector<int> balance = {-10, 10, 10, 10, 10, 10};
  // d=1: i=1(10) + i=5(10) = 20, take 10 → cost 10*1=10
  EXPECT_EQ(solution_.minMoves(balance), 10);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredNeedFromMultipleDistances) {
  // n=5, negative at 0, need=7
  // d=1: i=1(3), i=4(2) → total 5
  // d=2: i=2(4), i=3(1) → total 5
  std::vector<int> balance = {-7, 3, 4, 1, 2};
  // take 5 from d=1: cost 5*1=5, need 2
  // take 2 from d=2: cost 2*2=4, total=9
  EXPECT_EQ(solution_.minMoves(balance), 9);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredExactZeroSum) {
  std::vector<int> balance = {3, -3};
  // n=2, neg at 1, need=3. i=0 d=min(1,1)=1.
  // cost = 3*1 = 3
  EXPECT_EQ(solution_.minMoves(balance), 3);
}

TEST_P(MinimumMovesToBalanceCircularArrayTest, SelfAuthoredLargeValues) {
  // Large values within constraints.
  std::vector<int> balance = {1000000000, -1000000000};
  long long expected = 1000000000LL;  // d=1, need=1e9, cost=1e9
  EXPECT_EQ(solution_.minMoves(balance), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumMovesToBalanceCircularArrayTest,
    testing::ValuesIn(
        MinimumMovesToBalanceCircularArraySolution().getStrategyNames()));

}  // namespace problem_3776
}  // namespace leetcode
