#include <gtest/gtest.h>

#include "leetcode/problems/last-visited-integers.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2899 {

class LastVisitedIntegersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LastVisitedIntegersSolution solution;
};

TEST_P(LastVisitedIntegersTest, Example1) {
  std::vector<int> nums{1, 2, -1, -1, -1};
  std::vector<int> expected{2, 1, -1};
  EXPECT_EQ(expected, solution.lastVisitedIntegers(nums));
}

TEST_P(LastVisitedIntegersTest, Example2) {
  std::vector<int> nums{1, -1, 2, -1, -1};
  std::vector<int> expected{1, 2, 1};
  EXPECT_EQ(expected, solution.lastVisitedIntegers(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LastVisitedIntegersTestCases, LastVisitedIntegersTest,
    ::testing::ValuesIn(LastVisitedIntegersSolution().getStrategyNames()));

}  // namespace problem_2899
}  // namespace leetcode
