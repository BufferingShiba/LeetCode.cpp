#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/problems/count-elements-with-strictly-smaller-and-greater-elements.h"

namespace leetcode::problem_2148 {

class CountElementsWithStrictlySmallerAndGreaterElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CountElementsWithStrictlySmallerAndGreaterElementsSolution solution_;
};

TEST_P(CountElementsWithStrictlySmallerAndGreaterElementsTest, Example1) {
  std::vector<int> nums{11, 7, 2, 15};
  EXPECT_EQ(2, solution_.countElements(nums));
}

TEST_P(CountElementsWithStrictlySmallerAndGreaterElementsTest, Example2) {
  std::vector<int> nums{-3, 3, 3, 90};
  EXPECT_EQ(2, solution_.countElements(nums));
}

TEST_P(CountElementsWithStrictlySmallerAndGreaterElementsTest, SelfAuthoredAllSame) {
  std::vector<int> nums{5, 5, 5};
  EXPECT_EQ(0, solution_.countElements(nums));
}

TEST_P(CountElementsWithStrictlySmallerAndGreaterElementsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  EXPECT_EQ(0, solution_.countElements(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CountElementsWithStrictlySmallerAndGreaterElementsTestInstance,
    CountElementsWithStrictlySmallerAndGreaterElementsTest,
    ::testing::ValuesIn(
        CountElementsWithStrictlySmallerAndGreaterElementsSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_2148
