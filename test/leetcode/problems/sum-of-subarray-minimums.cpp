#include "leetcode/problems/sum-of-subarray-minimums.h"

#include <gtest/gtest.h>
#include <vector>

namespace leetcode::problem_907 {

class SumOfSubarrayMinimumsTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

 protected:
  SumOfSubarrayMinimumsSolution solution_;
};

TEST_P(SumOfSubarrayMinimumsTest, Example1) {
  std::vector<int> arr{3, 1, 2, 4};
  EXPECT_EQ(17, solution_.sumSubarrayMins(arr));
}

TEST_P(SumOfSubarrayMinimumsTest, Example2) {
  std::vector<int> arr{11, 81, 94, 43, 3};
  EXPECT_EQ(444, solution_.sumSubarrayMins(arr));
}

TEST_P(SumOfSubarrayMinimumsTest, SelfAuthoredSingleElement) {
  std::vector<int> arr{5};
  EXPECT_EQ(5, solution_.sumSubarrayMins(arr));
}

TEST_P(SumOfSubarrayMinimumsTest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> arr{1, 2, 3, 4};
  // Subarrays mins: single: 1+2+3+4; pairs: 1+2+3; triples: 1+2; quad: 1
  EXPECT_EQ(20, solution_.sumSubarrayMins(arr));
}

TEST_P(SumOfSubarrayMinimumsTest, SelfAuthoredAllEqual) {
  std::vector<int> arr{2, 2, 2};
  // Each of 6 subarrays has min 2 => 12
  EXPECT_EQ(12, solution_.sumSubarrayMins(arr));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfSubarrayMinimumsTestSuite, SumOfSubarrayMinimumsTest,
    ::testing::ValuesIn(SumOfSubarrayMinimumsSolution().getStrategyNames()));

}  // namespace leetcode::problem_907
