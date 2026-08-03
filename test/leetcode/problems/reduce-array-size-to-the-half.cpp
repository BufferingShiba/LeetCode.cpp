#include <gtest/gtest.h>

#include "leetcode/problems/reduce-array-size-to-the-half.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1338 {

class ReduceArraySizeToTheHalfTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  ReduceArraySizeToTheHalfSolution solution;
};

TEST_P(ReduceArraySizeToTheHalfTest, Example1) {
  std::vector<int> arr{3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
  EXPECT_EQ(2, solution.minSetSize(arr));
}

TEST_P(ReduceArraySizeToTheHalfTest, Example2) {
  std::vector<int> arr{7, 7, 7, 7, 7, 7};
  EXPECT_EQ(1, solution.minSetSize(arr));
}

TEST_P(ReduceArraySizeToTheHalfTest, SelfAuthoredAllDistinct) {
  std::vector<int> arr{1, 2, 3, 4};
  EXPECT_EQ(2, solution.minSetSize(arr));
}

TEST_P(ReduceArraySizeToTheHalfTest, SelfAuthoredLargeSingleValue) {
  std::vector<int> arr(100000, 5);
  EXPECT_EQ(1, solution.minSetSize(arr));
}

INSTANTIATE_TEST_SUITE_P(
    ReduceArraySizeToTheHalfSuite,
    ReduceArraySizeToTheHalfTest,
    ::testing::ValuesIn(ReduceArraySizeToTheHalfSolution().getStrategyNames()));

}  // namespace problem_1338
}  // namespace leetcode
