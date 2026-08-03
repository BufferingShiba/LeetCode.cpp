#include "leetcode/problems/maximum-or.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2680 {

class MaximumOrTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumOrSolution solution;
};

TEST_P(MaximumOrTest, Example1) {
  std::vector<int> nums{12, 9};
  int k = 1;
  EXPECT_EQ(30, solution.getSolution()(nums, k));
}

TEST_P(MaximumOrTest, Example2) {
  std::vector<int> nums{8, 1, 2};
  int k = 2;
  EXPECT_EQ(35, solution.getSolution()(nums, k));
}

TEST_P(MaximumOrTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  int k = 3;
  EXPECT_EQ(static_cast<long long>(5) << 3, solution.getSolution()(nums, k));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumOrTestCases, MaximumOrTest,
    ::testing::ValuesIn(MaximumOrSolution().getStrategyNames()));

}  // namespace problem_2680
}  // namespace leetcode
