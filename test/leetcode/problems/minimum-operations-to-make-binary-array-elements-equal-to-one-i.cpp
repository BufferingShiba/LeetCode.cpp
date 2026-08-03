#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i.h"

namespace leetcode {
namespace problem_3191 {

namespace {

std::vector<int> vec(std::initializer_list<int> il) {
  return std::vector<int>(il);
}

}  // namespace

class MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution solution_;
};

TEST_P(MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
       Example1) {
  std::vector<int> nums = vec({0, 1, 1, 1, 0, 0});
  EXPECT_EQ(3, solution_.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
       Example2) {
  std::vector<int> nums = vec({0, 1, 1, 1});
  EXPECT_EQ(-1, solution_.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
       AlreadyAllOnes) {
  std::vector<int> nums = vec({1, 1, 1, 1, 1});
  EXPECT_EQ(0, solution_.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
       ShortSolvable) {
  std::vector<int> nums = vec({0, 0, 0});
  EXPECT_EQ(1, solution_.minOperations(nums));
}

TEST_P(MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
       ShortImpossible) {
  std::vector<int> nums = vec({1, 0, 1});
  EXPECT_EQ(-1, solution_.minOperations(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
    MinimumOperationsToMakeBinaryArrayElementsEqualToOneITest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeBinaryArrayElementsEqualToOneISolution()
            .getStrategyNames()));

}  // namespace problem_3191
}  // namespace leetcode
