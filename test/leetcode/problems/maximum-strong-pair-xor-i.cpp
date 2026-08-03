#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-strong-pair-xor-i.h"

namespace leetcode {
namespace problem_2932 {

class MaximumStrongPairXorITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumStrongPairXorISolution solution;
};

TEST_P(MaximumStrongPairXorITest, Example1) {
  std::vector<int> nums{1, 2, 3, 4, 5};
  EXPECT_EQ(7, solution.maximumStrongPairXor(nums));
}

TEST_P(MaximumStrongPairXorITest, Example2) {
  std::vector<int> nums{10, 100};
  EXPECT_EQ(0, solution.maximumStrongPairXor(nums));
}

TEST_P(MaximumStrongPairXorITest, Example3) {
  std::vector<int> nums{5, 6, 25, 30};
  EXPECT_EQ(7, solution.maximumStrongPairXor(nums));
}

TEST_P(MaximumStrongPairXorITest, SelfAuthoredSingleElement) {
  std::vector<int> nums{42};
  EXPECT_EQ(0, solution.maximumStrongPairXor(nums));
}

TEST_P(MaximumStrongPairXorITest, SelfAuthoredAllEqual) {
  std::vector<int> nums{7, 7, 7};
  EXPECT_EQ(0, solution.maximumStrongPairXor(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumStrongPairXorITestSuite, MaximumStrongPairXorITest,
    ::testing::ValuesIn(MaximumStrongPairXorISolution().getStrategyNames()));

}  // namespace problem_2932
}  // namespace leetcode
