#include <gtest/gtest.h>

#include "leetcode/problems/distribute-repeating-integers.h"

namespace leetcode {
namespace problem_1655 {

class DistributeRepeatingIntegersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  DistributeRepeatingIntegersSolution solution;
};

TEST_P(DistributeRepeatingIntegersTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> quantity = {2};
  EXPECT_FALSE(solution.canDistribute(nums, quantity));
}

TEST_P(DistributeRepeatingIntegersTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 3};
  std::vector<int> quantity = {2};
  EXPECT_TRUE(solution.canDistribute(nums, quantity));
}

TEST_P(DistributeRepeatingIntegersTest, Example3) {
  std::vector<int> nums = {1, 1, 2, 2};
  std::vector<int> quantity = {2, 2};
  EXPECT_TRUE(solution.canDistribute(nums, quantity));
}

TEST_P(DistributeRepeatingIntegersTest, EdgeSingle) {
  std::vector<int> nums = {1};
  std::vector<int> quantity = {1};
  EXPECT_TRUE(solution.canDistribute(nums, quantity));
  std::vector<int> nums2 = {1};
  std::vector<int> quantity2 = {2};
  EXPECT_FALSE(solution.canDistribute(nums2, quantity2));
}

TEST_P(DistributeRepeatingIntegersTest, EdgeAllSame) {
  std::vector<int> nums = {1, 1, 1};
  std::vector<int> quantity = {2, 1};
  EXPECT_TRUE(solution.canDistribute(nums, quantity));
  std::vector<int> nums2 = {1, 1, 1};
  std::vector<int> quantity2 = {2, 2};
  EXPECT_FALSE(solution.canDistribute(nums2, quantity2));
}

TEST_P(DistributeRepeatingIntegersTest, EdgeSplit) {
  std::vector<int> nums = {1, 2, 2, 3, 3, 3};
  std::vector<int> quantity = {2, 3};
  EXPECT_TRUE(solution.canDistribute(nums, quantity));
  // Each distinct value has freq 1; three customers each need 1 -> true.
  std::vector<int> nums2 = {1, 2, 3};
  std::vector<int> quantity2 = {1, 1, 1};
  EXPECT_TRUE(solution.canDistribute(nums2, quantity2));
  // No value has freq >= 2 -> false.
  std::vector<int> nums3 = {1, 2, 3};
  std::vector<int> quantity3 = {2};
  EXPECT_FALSE(solution.canDistribute(nums3, quantity3));
  // Multiple customers must split a single large frequency.
  std::vector<int> nums4 = {1, 1, 1};
  std::vector<int> quantity4 = {1, 1, 1};
  EXPECT_TRUE(solution.canDistribute(nums4, quantity4));
}

INSTANTIATE_TEST_SUITE_P(
    DistributeRepeatingIntegersVariants, DistributeRepeatingIntegersTest,
    ::testing::ValuesIn(DistributeRepeatingIntegersSolution().getStrategyNames()));

}  // namespace problem_1655
}  // namespace leetcode
