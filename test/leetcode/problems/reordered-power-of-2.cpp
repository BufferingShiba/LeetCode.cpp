#include <gtest/gtest.h>

#include "leetcode/problems/reordered-power-of-2.h"

namespace leetcode {
namespace problem_869 {

class ReorderedPowerOf2Test : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  ReorderedPowerOf2Solution solution;
};

TEST_P(ReorderedPowerOf2Test, OfficialExamples) {
  EXPECT_TRUE(solution.reorderedPowerOf2(1));
  EXPECT_FALSE(solution.reorderedPowerOf2(10));
}

TEST_P(ReorderedPowerOf2Test, SelfAuthored) {
  // 46 can be reordered to 64 which is 2^6
  EXPECT_TRUE(solution.reorderedPowerOf2(46));
  // 24 -> 42? No. But 2^? = 42 no. 24 itself not power of 2.
  EXPECT_FALSE(solution.reorderedPowerOf2(24));
  // 2^0 = 1
  EXPECT_TRUE(solution.reorderedPowerOf2(1));
  // 2 itself
  EXPECT_TRUE(solution.reorderedPowerOf2(2));
  // 3 -> no power of 2
  EXPECT_FALSE(solution.reorderedPowerOf2(3));
  // 125 can be reordered to 512 (2^9)
  EXPECT_TRUE(solution.reorderedPowerOf2(125));
  // Large number: 536870912 is 2^29, reorder should match itself
  EXPECT_TRUE(solution.reorderedPowerOf2(536870912));
  // 536870913 -> one digit off from 2^29
  EXPECT_FALSE(solution.reorderedPowerOf2(536870913));
  // 1000000000 (10^9) -> has 9 zeros and a 1, no power of 2 has that
  EXPECT_FALSE(solution.reorderedPowerOf2(1000000000));
}

INSTANTIATE_TEST_SUITE_P(,
                         ReorderedPowerOf2Test,
                         testing::ValuesIn(
                             ReorderedPowerOf2Solution().getStrategyNames()));

}  // namespace problem_869
}  // namespace leetcode
