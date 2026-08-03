#include <gtest/gtest.h>

#include "leetcode/problems/valid-elements-in-an-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3912 {

class ValidElementsInAnArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  ValidElementsInAnArray solution;

  std::vector<int> run(std::vector<int> nums) {
    return solution.findValidElements(nums);
  }
};

TEST_P(ValidElementsInAnArrayTest, Example1) {
  std::vector<int> input{1, 2, 4, 2, 3, 2};
  std::vector<int> expected{1, 2, 4, 3, 2};
  EXPECT_EQ(expected, run(input));
}

TEST_P(ValidElementsInAnArrayTest, Example2) {
  std::vector<int> input{5, 5, 5, 5};
  std::vector<int> expected{5, 5};
  EXPECT_EQ(expected, run(input));
}

TEST_P(ValidElementsInAnArrayTest, Example3) {
  std::vector<int> input{1};
  std::vector<int> expected{1};
  EXPECT_EQ(expected, run(input));
}

TEST_P(ValidElementsInAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> input{7};
  std::vector<int> expected{7};
  EXPECT_EQ(expected, run(input));
}

TEST_P(ValidElementsInAnArrayTest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> input{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  EXPECT_EQ(expected, run(input));
}

TEST_P(ValidElementsInAnArrayTest, SelfAuthoredDecreasing) {
  std::vector<int> input{5, 4, 3, 2, 1};
  std::vector<int> expected{5, 4, 3, 2, 1};
  EXPECT_EQ(expected, run(input));
}

INSTANTIATE_TEST_SUITE_P(
    ValidElementsInAnArrayTestSuite,
    ValidElementsInAnArrayTest,
    ::testing::ValuesIn(ValidElementsInAnArray().getStrategyNames()));

}  // namespace problem_3912
}  // namespace leetcode
