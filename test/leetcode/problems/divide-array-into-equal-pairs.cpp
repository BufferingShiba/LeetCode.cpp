#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/divide-array-into-equal-pairs.h"

namespace leetcode::problem_2206 {

using DivideArrayIntoEqualPairsTest = ::testing::TestWithParam<std::string>;

class DivideArrayIntoEqualPairsParamTest
    : public DivideArrayIntoEqualPairsTest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  DivideArrayIntoEqualPairsSolution solution_;
};

TEST_P(DivideArrayIntoEqualPairsParamTest, Example1) {
  std::vector<int> nums{3, 2, 3, 2, 2, 2};
  EXPECT_TRUE(solution_.divideArray(nums));
}

TEST_P(DivideArrayIntoEqualPairsParamTest, Example2) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_FALSE(solution_.divideArray(nums));
}

TEST_P(DivideArrayIntoEqualPairsParamTest, SelfAuthoredAllDistinctValuesInPairs) {
  std::vector<int> nums{5, 5, 7, 7, 9, 9};
  EXPECT_TRUE(solution_.divideArray(nums));
}

INSTANTIATE_TEST_SUITE_P(
    DivideArrayIntoEqualPairsTestSuite, DivideArrayIntoEqualPairsParamTest,
    ::testing::ValuesIn(DivideArrayIntoEqualPairsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2206
