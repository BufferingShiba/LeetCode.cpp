#include <gtest/gtest.h>

#include "leetcode/problems/divide-an-array-into-subarrays-with-minimum-cost-i.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3010 {
namespace test {

class DivideAnArrayIntoSubarraysWithMinimumCostITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DivideAnArrayIntoSubarraysWithMinimumCostISolution solution;
};

TEST_P(DivideAnArrayIntoSubarraysWithMinimumCostITest, Example1) {
  std::vector<int> nums = {1, 2, 3, 12};
  EXPECT_EQ(6, solution.minimumCost(nums));
}

TEST_P(DivideAnArrayIntoSubarraysWithMinimumCostITest, Example2) {
  std::vector<int> nums = {5, 4, 3};
  EXPECT_EQ(12, solution.minimumCost(nums));
}

TEST_P(DivideAnArrayIntoSubarraysWithMinimumCostITest, Example3) {
  std::vector<int> nums = {10, 3, 1, 1};
  EXPECT_EQ(12, solution.minimumCost(nums));
}

TEST_P(DivideAnArrayIntoSubarraysWithMinimumCostITest, SelfAuthoredAllSameValues) {
  std::vector<int> nums = {4, 4, 4, 4, 4};
  EXPECT_EQ(12, solution.minimumCost(nums));
}

INSTANTIATE_TEST_SUITE_P(
    Problem3010, DivideAnArrayIntoSubarraysWithMinimumCostITest,
    ::testing::ValuesIn(
        DivideAnArrayIntoSubarraysWithMinimumCostISolution()
            .getStrategyNames()));

}  // namespace test
}  // namespace problem_3010
}  // namespace leetcode
