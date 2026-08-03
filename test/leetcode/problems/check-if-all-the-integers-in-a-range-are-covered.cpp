#include <gtest/gtest.h>

#include "leetcode/problems/check-if-all-the-integers-in-a-range-are-covered.h"

namespace leetcode {
namespace problem_1893 {

class CheckIfAllTheIntegersInARangeAreCoveredTest : public ::testing::TestWithParam<std::string> {
 protected:
  CheckIfAllTheIntegersInARangeAreCoveredSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(CheckIfAllTheIntegersInARangeAreCoveredTest, Example1) {
  std::vector<std::vector<int>> ranges = {{1, 2}, {3, 4}, {5, 6}};
  int left = 2, right = 5;
  EXPECT_TRUE(solution.isCovered(ranges, left, right));
}

TEST_P(CheckIfAllTheIntegersInARangeAreCoveredTest, Example2) {
  std::vector<std::vector<int>> ranges = {{1, 10}, {10, 20}};
  int left = 21, right = 21;
  EXPECT_FALSE(solution.isCovered(ranges, left, right));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfAllTheIntegersInARangeAreCoveredTest,
    ::testing::ValuesIn(CheckIfAllTheIntegersInARangeAreCoveredSolution().getStrategyNames())
);

}  // namespace problem_1893
}  // namespace leetcode
