#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-transform-array-into-alternating-prime.h"

namespace leetcode {
namespace problem_3896 {

class MinimumOperationsToTransformArrayIntoAlternatingPrimeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution solution_;
};

TEST_P(MinimumOperationsToTransformArrayIntoAlternatingPrimeTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_EQ(solution_.minOperations(nums), 3);
}

TEST_P(MinimumOperationsToTransformArrayIntoAlternatingPrimeTest, Example2) {
  std::vector<int> nums = {5, 6, 7, 8};
  EXPECT_EQ(solution_.minOperations(nums), 0);
}

TEST_P(MinimumOperationsToTransformArrayIntoAlternatingPrimeTest, Example3) {
  std::vector<int> nums = {4, 4};
  EXPECT_EQ(solution_.minOperations(nums), 1);
}

TEST_P(MinimumOperationsToTransformArrayIntoAlternatingPrimeTest,
       SelfAuthored) {
  // Single element at even index (0) must be prime
  {
    std::vector<int> nums = {1};
    EXPECT_EQ(solution_.minOperations(nums), 1);  // 1 -> 2
  }
  {
    std::vector<int> nums = {2};
    EXPECT_EQ(solution_.minOperations(nums), 0);  // already prime
  }
  {
    std::vector<int> nums = {4};
    EXPECT_EQ(solution_.minOperations(nums), 1);  // 4 -> 5
  }

  // Two elements: odd index non-prime
  {
    std::vector<int> nums = {2, 2};
    // idx 0: 2 prime -> 0; idx 1: 2 prime -> need non-prime -> 2->4 (+2)
    EXPECT_EQ(solution_.minOperations(nums), 2);
  }
  {
    std::vector<int> nums = {2, 3};
    // idx 0: 2 prime -> 0; idx 1: 3 prime -> 3->4 (+1)
    EXPECT_EQ(solution_.minOperations(nums), 1);
  }

  // Larger values near 100000
  {
    std::vector<int> nums = {100000, 100000};
    // idx 0: 100000 -> next prime 100003 (+3); idx 1: 100000 non-prime -> 0
    EXPECT_EQ(solution_.minOperations(nums), 3);
  }

  // Edge: 1 at odd index (already non-prime)
  {
    std::vector<int> nums = {2, 1};
    EXPECT_EQ(solution_.minOperations(nums), 0);
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumOperationsToTransformArrayIntoAlternatingPrimeTest,
    ::testing::ValuesIn(
        MinimumOperationsToTransformArrayIntoAlternatingPrimeSolution()
            .getStrategyNames()));

}  // namespace problem_3896
}  // namespace leetcode
