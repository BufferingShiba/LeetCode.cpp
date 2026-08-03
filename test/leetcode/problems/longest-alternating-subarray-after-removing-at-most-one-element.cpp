#include "leetcode/problems/longest-alternating-subarray-after-removing-at-most-one-element.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3830 {

using Solver = LongestAlternatingSubarrayAfterRemovingAtMostOneElementSolution;

class LongestAlternatingSubarrayAfterRemovingAtMostOneElementTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  Solver solution_;
};

TEST_P(LongestAlternatingSubarrayAfterRemovingAtMostOneElementTest,
       Example1) {
  std::vector<int> nums{2, 1, 3, 2};
  EXPECT_EQ(4, solution_.longestAlternating(nums));
}

TEST_P(LongestAlternatingSubarrayAfterRemovingAtMostOneElementTest,
       Example2) {
  std::vector<int> nums{3, 2, 1, 2, 3, 2, 1};
  EXPECT_EQ(4, solution_.longestAlternating(nums));
}

TEST_P(LongestAlternatingSubarrayAfterRemovingAtMostOneElementTest,
       Example3) {
  std::vector<int> nums{100000, 100000};
  EXPECT_EQ(1, solution_.longestAlternating(nums));
}

TEST_P(LongestAlternatingSubarrayAfterRemovingAtMostOneElementTest,
       SelfAuthored) {
  {
    // 交替段 1<3>2<4 整段可用，长度 4。
    std::vector<int> nums{1, 3, 2, 4};
    EXPECT_EQ(4, solution_.longestAlternating(nums));
  }
  {
    // 删除 idx0 得 [1,2,1] = 1<2>1 交替，长度 3。
    std::vector<int> nums{1, 1, 2, 1};
    EXPECT_EQ(3, solution_.longestAlternating(nums));
  }
  {
    // 相等对阻断延伸；删除任一 2 后仍是单调递增，最长交替段长为 2。
    std::vector<int> nums{1, 2, 2, 3};
    EXPECT_EQ(2, solution_.longestAlternating(nums));
  }
}

INSTANTIATE_TEST_SUITE_P(
    LongestAlternatingSubarrayAfterRemovingAtMostOneElementTestInstance,
    LongestAlternatingSubarrayAfterRemovingAtMostOneElementTest,
    ::testing::ValuesIn(Solver().getStrategyNames()));

}  // namespace problem_3830
}  // namespace leetcode
