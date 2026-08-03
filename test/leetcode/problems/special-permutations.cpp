#include <gtest/gtest.h>

#include "leetcode/problems/special-permutations.h"

namespace leetcode {
namespace problem_2741 {

class SpecialPermutationsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  SpecialPermutationsSolution solution_;
};

TEST_P(SpecialPermutationsTest, Example1) {
  std::vector<int> nums = {2, 3, 6};
  EXPECT_EQ(solution_.specialPerm(nums), 2);
}

TEST_P(SpecialPermutationsTest, Example2) {
  std::vector<int> nums = {1, 4, 3};
  EXPECT_EQ(solution_.specialPerm(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies,
                         SpecialPermutationsTest,
                         ::testing::ValuesIn(
                             SpecialPermutationsSolution().getStrategyNames()));

}  // namespace problem_2741
}  // namespace leetcode
