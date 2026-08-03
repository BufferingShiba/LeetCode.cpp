#include <gtest/gtest.h>

#include "leetcode/problems/split-array-by-prime-indices.h"

namespace leetcode {
namespace problem_3618 {

class SplitArrayByPrimeIndicesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  SplitArrayByPrimeIndicesSolution solution_;
};

TEST_P(SplitArrayByPrimeIndicesTest, Example1) {
  std::vector<int> nums = {2, 3, 4};
  EXPECT_EQ(solution_.splitArray(nums), 1);
}

TEST_P(SplitArrayByPrimeIndicesTest, Example2) {
  std::vector<int> nums = {-1, 5, 7, 0};
  EXPECT_EQ(solution_.splitArray(nums), 3);
}

TEST_P(SplitArrayByPrimeIndicesTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  // index 0 → not prime → all in B
  EXPECT_EQ(solution_.splitArray(nums), 5);
}

TEST_P(SplitArrayByPrimeIndicesTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {10, 20};
  // indices 0,1 → not prime → all in B
  EXPECT_EQ(solution_.splitArray(nums), 30);
}

TEST_P(SplitArrayByPrimeIndicesTest, SelfAuthoredIndex2IsPrime) {
  std::vector<int> nums = {1, 1, 1};
  // index 2 is prime → A=[1], B=[1,1] → |1-2|=1
  EXPECT_EQ(solution_.splitArray(nums), 1);
}

TEST_P(SplitArrayByPrimeIndicesTest, SelfAuthoredLargerN) {
  // n=6: prime indices 2,3,5; non-prime 0,1,4
  std::vector<int> nums = {10, 20, 30, 40, 50, 60};
  // A: 30+40+60=130; B: 10+20+50=80 → diff=50
  EXPECT_EQ(solution_.splitArray(nums), 50);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SplitArrayByPrimeIndicesTest,
    testing::ValuesIn(SplitArrayByPrimeIndicesSolution().getStrategyNames()));

}  // namespace problem_3618
}  // namespace leetcode
