#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-special-quadruplets.h"

namespace leetcode {
namespace problem_1995 {

class CountSpecialQuadrupletsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSpecialQuadrupletsSolution solution;
};

TEST_P(CountSpecialQuadrupletsTest, Example1) {
  std::vector<int> nums{1, 2, 3, 6};
  EXPECT_EQ(1, solution.countQuadruplets(nums));
}

TEST_P(CountSpecialQuadrupletsTest, Example2) {
  std::vector<int> nums{3, 3, 6, 4, 5};
  EXPECT_EQ(0, solution.countQuadruplets(nums));
}

TEST_P(CountSpecialQuadrupletsTest, Example3) {
  std::vector<int> nums{1, 1, 1, 3, 5};
  EXPECT_EQ(4, solution.countQuadruplets(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CountSpecialQuadruplets, CountSpecialQuadrupletsTest,
    ::testing::ValuesIn(CountSpecialQuadrupletsSolution().getStrategyNames()));

}  // namespace problem_1995
}  // namespace leetcode
