#include "leetcode/problems/range-module.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode {
namespace problem_715 {

class RangeModuleTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { unused_ = GetParam(); }
  int unused_;
};

TEST_P(RangeModuleTest, Example1) {
  RangeModule rm;
  rm.addRange(10, 20);
  rm.removeRange(14, 16);
  EXPECT_TRUE(rm.queryRange(10, 14));
  EXPECT_FALSE(rm.queryRange(13, 15));
  EXPECT_TRUE(rm.queryRange(16, 17));
}

TEST_P(RangeModuleTest, SelfAuthoredAddMerge) {
  RangeModule rm;
  rm.addRange(10, 20);
  rm.addRange(15, 25);
  EXPECT_TRUE(rm.queryRange(10, 25));
  rm.addRange(5, 12);
  EXPECT_TRUE(rm.queryRange(5, 25));
}

TEST_P(RangeModuleTest, SelfAuthoredRemoveMiddle) {
  RangeModule rm;
  rm.addRange(10, 20);
  rm.removeRange(12, 15);
  EXPECT_TRUE(rm.queryRange(10, 12));
  EXPECT_FALSE(rm.queryRange(10, 15));
  EXPECT_FALSE(rm.queryRange(13, 14));
  EXPECT_TRUE(rm.queryRange(15, 20));
  EXPECT_TRUE(rm.queryRange(16, 18));
  EXPECT_FALSE(rm.queryRange(11, 16));
}

TEST_P(RangeModuleTest, SelfAuthoredRemoveLeftEdge) {
  RangeModule rm;
  rm.addRange(10, 20);
  rm.removeRange(5, 15);
  EXPECT_FALSE(rm.queryRange(5, 15));
  EXPECT_TRUE(rm.queryRange(15, 20));
}

TEST_P(RangeModuleTest, SelfAuthoredRemoveRightEdge) {
  RangeModule rm;
  rm.addRange(10, 20);
  rm.removeRange(15, 25);
  EXPECT_TRUE(rm.queryRange(10, 15));
  EXPECT_FALSE(rm.queryRange(15, 20));
}

TEST_P(RangeModuleTest, SelfAuthoredRemoveAll) {
  RangeModule rm;
  rm.addRange(10, 20);
  rm.removeRange(10, 20);
  EXPECT_FALSE(rm.queryRange(10, 20));
  EXPECT_FALSE(rm.queryRange(15, 16));
  // 空状态下的操作
  rm.addRange(1, 2);
  rm.removeRange(0, 10);
  EXPECT_FALSE(rm.queryRange(1, 2));
}

INSTANTIATE_TEST_SUITE_P(RangeModuleSuite, RangeModuleTest,
                         ::testing::Values(0));

}  // namespace problem_715
}  // namespace leetcode
