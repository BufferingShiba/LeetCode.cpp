#include "leetcode/problems/minimum-impossible-or.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2568 {

class MinimumImpossibleOrTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumImpossibleOrSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  nums = [2,1]
// Output: 4
TEST_P(MinimumImpossibleOrTest, OfficialExample1) {
  std::vector<int> nums{2, 1};
  EXPECT_EQ(4, solution.minImpossibleOR(nums));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  nums = [5,3,2]
// Output: 1
TEST_P(MinimumImpossibleOrTest, OfficialExample2) {
  std::vector<int> nums{5, 3, 2};
  EXPECT_EQ(1, solution.minImpossibleOR(nums));
}

// ===== SelfAuthored Case: all powers of two up to 8 present =====
// nums = [1,2,4,8] -> 1,2,3,...,15 expressible; 16 is not present.
TEST_P(MinimumImpossibleOrTest, PowersOfTwo) {
  std::vector<int> nums{1, 2, 4, 8};
  EXPECT_EQ(16, solution.minImpossibleOR(nums));
}

// ===== SelfAuthored Case: single element =====
// nums = [4] -> only 4 expressible; 1 is not.
TEST_P(MinimumImpossibleOrTest, SingleElement) {
  std::vector<int> nums{4};
  EXPECT_EQ(1, solution.minImpossibleOR(nums));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumImpossibleOrTest,
    ::testing::ValuesIn(MinimumImpossibleOrSolution().getStrategyNames()));

}  // namespace problem_2568
}  // namespace leetcode
