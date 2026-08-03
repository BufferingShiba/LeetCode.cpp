#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/design-bitset.h"

namespace leetcode {
namespace problem_2166 {

class DesignBitsetTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(DesignBitsetTest, OfficialExample) {
  // ops: fix(3), fix(1), flip, all==false, unfix(0), flip, one==true,
  //       unfix(0), count==2, toString=="01010"
  Bitset bs(5);
  bs.fix(3);
  bs.fix(1);
  bs.flip();
  EXPECT_FALSE(bs.all());
  bs.unfix(0);
  bs.flip();
  EXPECT_TRUE(bs.one());
  bs.unfix(0);
  EXPECT_EQ(2, bs.count());
  EXPECT_EQ("01010", bs.toString());
}

TEST_P(DesignBitsetTest, SelfAuthoredFlipAndAll) {
  Bitset bs(3);
  EXPECT_FALSE(bs.one());
  EXPECT_FALSE(bs.all());
  bs.flip();
  EXPECT_TRUE(bs.all());
  EXPECT_EQ("111", bs.toString());
  bs.unfix(1);
  EXPECT_EQ("101", bs.toString());
  bs.flip();
  EXPECT_EQ("010", bs.toString());
  EXPECT_EQ(1, bs.count());
}

TEST_P(DesignBitsetTest, SelfAuthoredIdempotentFixUnfix) {
  Bitset bs(4);
  bs.fix(0);
  bs.fix(0);
  bs.fix(0);
  EXPECT_EQ(1, bs.count());
  bs.unfix(0);
  bs.unfix(0);
  EXPECT_EQ(0, bs.count());
}

TEST_P(DesignBitsetTest, SelfAuthoredSingleBit) {
  Bitset bs(1);
  EXPECT_EQ("0", bs.toString());
  EXPECT_TRUE(bs.one() == false);
  bs.fix(0);
  EXPECT_TRUE(bs.all());
  EXPECT_TRUE(bs.one());
  bs.flip();
  EXPECT_FALSE(bs.all());
  EXPECT_FALSE(bs.one());
}

INSTANTIATE_TEST_SUITE_P(DesignBitsetTestSuite, DesignBitsetTest,
                         ::testing::Values(0));

}  // namespace problem_2166
}  // namespace leetcode
