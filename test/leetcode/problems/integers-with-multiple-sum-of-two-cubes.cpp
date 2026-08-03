#include "leetcode/problems/integers-with-multiple-sum-of-two-cubes.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3890 {

class IntegersWithMultipleSumOfTwoCubesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  IntegersWithMultipleSumOfTwoCubesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  n = 4104
// Output: [1729,4104]
TEST_P(IntegersWithMultipleSumOfTwoCubesTest, OfficialExample1) {
  std::vector<int> expected = {1729, 4104};
  EXPECT_EQ(solution.findGoodIntegers(4104), expected);
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  n = 578
// Output: []
TEST_P(IntegersWithMultipleSumOfTwoCubesTest, OfficialExample2) {
  std::vector<int> expected;
  EXPECT_EQ(solution.findGoodIntegers(578), expected);
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, IntegersWithMultipleSumOfTwoCubesTest,
    ::testing::ValuesIn(IntegersWithMultipleSumOfTwoCubesSolution().getStrategyNames()));

}  // namespace problem_3890
}  // namespace leetcode
