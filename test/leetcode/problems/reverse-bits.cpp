#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reverse-bits.h"

namespace leetcode::problem_190 {

class ReverseBitsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 public:
  ReverseBits solution_;
};

TEST_P(ReverseBitsTest, Example1) {
  EXPECT_EQ(solution_.reverseBits(43261596), 964176192);
}

TEST_P(ReverseBitsTest, Example2) {
  EXPECT_EQ(solution_.reverseBits(2147483644), 1073741822);
}

TEST_P(ReverseBitsTest, Zero) {
  EXPECT_EQ(solution_.reverseBits(0), 0);
}

TEST_P(ReverseBitsTest, One) {
  EXPECT_EQ(solution_.reverseBits(1), 1 << 31);
}

INSTANTIATE_TEST_SUITE_P(
    ReverseBitsTestSuite, ReverseBitsTest,
    ::testing::ValuesIn(ReverseBits().getStrategyNames()));

}  // namespace leetcode::problem_190
