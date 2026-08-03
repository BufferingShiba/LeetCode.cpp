#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/find-indices-with-index-and-value-difference-i.h"

namespace leetcode {
namespace problem_2903 {

class FindIndicesWithIndexAndValueDifferenceITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  FindIndicesWithIndexAndValueDifferenceISolution solution;
};

TEST_P(FindIndicesWithIndexAndValueDifferenceITest, Example1) {
  std::vector<int> nums = {5, 1, 4, 1};
  std::vector<int> result = solution.findIndices(nums, 2, 4);
  ASSERT_EQ(result.size(), 2u);
  EXPECT_GE(std::abs(result[0] - result[1]), 2);
  EXPECT_GE(std::abs(nums[result[0]] - nums[result[1]]), 4);
}

TEST_P(FindIndicesWithIndexAndValueDifferenceITest, Example2) {
  std::vector<int> nums = {2, 1};
  std::vector<int> result = solution.findIndices(nums, 0, 0);
  ASSERT_EQ(result.size(), 2u);
  EXPECT_GE(std::abs(result[0] - result[1]), 0);
  EXPECT_GE(std::abs(nums[result[0]] - nums[result[1]]), 0);
}

TEST_P(FindIndicesWithIndexAndValueDifferenceITest, Example3) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> result = solution.findIndices(nums, 2, 4);
  EXPECT_EQ(result, (std::vector<int>{-1, -1}));
}

TEST_P(FindIndicesWithIndexAndValueDifferenceITest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  std::vector<int> result = solution.findIndices(nums, 0, 0);
  ASSERT_EQ(result.size(), 2u);
  EXPECT_GE(std::abs(result[0] - result[1]), 0);
  EXPECT_GE(std::abs(nums[result[0]] - nums[result[1]]), 0);
}

TEST_P(FindIndicesWithIndexAndValueDifferenceITest, SelfAuthoredImpossibleCase) {
  std::vector<int> nums = {2, 2, 2};
  std::vector<int> result = solution.findIndices(nums, 2, 1);
  EXPECT_EQ(result, (std::vector<int>{-1, -1}));
}

INSTANTIATE_TEST_SUITE_P(
    FindIndicesWithIndexAndValueDifferenceITestSuite,
    FindIndicesWithIndexAndValueDifferenceITest,
    ::testing::ValuesIn(
        FindIndicesWithIndexAndValueDifferenceISolution().getStrategyNames()));

}  // namespace problem_2903
}  // namespace leetcode
