#include <gtest/gtest.h>

#include "leetcode/problems/number-of-even-and-odd-bits.h"

namespace leetcode {
namespace problem_2595 {

class NumberOfEvenAndOddBitsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfEvenAndOddBitsSolution solution_;
};

TEST_P(NumberOfEvenAndOddBitsTest, OfficialExamples) {
  EXPECT_EQ(solution_.evenOddBit(50), (std::vector<int>{1, 2}));
  EXPECT_EQ(solution_.evenOddBit(2), (std::vector<int>{0, 1}));
}

TEST_P(NumberOfEvenAndOddBitsTest, SelfAuthored) {
  // n=1: binary "1", index 0 (even) = 1 → [1,0]
  EXPECT_EQ(solution_.evenOddBit(1), (std::vector<int>{1, 0}));
  // n=3: binary "11", index 0=1 (even), index 1=1 (odd) → [1,1]
  EXPECT_EQ(solution_.evenOddBit(3), (std::vector<int>{1, 1}));
  // n=1000: binary "1111101000"
  // bits: 0:0,1:0,2:0,3:1,4:0,5:1,6:1,7:1,8:1,9:1
  // even indices with 1: 6,8 → even=2
  // odd indices with 1: 3,5,7,9 → odd=4
  EXPECT_EQ(solution_.evenOddBit(1000), (std::vector<int>{2, 4}));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfEvenAndOddBitsTest,
    testing::ValuesIn(NumberOfEvenAndOddBitsSolution().getStrategyNames()));

}  // namespace problem_2595
}  // namespace leetcode
