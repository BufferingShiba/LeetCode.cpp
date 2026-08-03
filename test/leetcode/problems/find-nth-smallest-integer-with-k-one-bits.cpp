#include <gtest/gtest.h>

#include "leetcode/problems/find-nth-smallest-integer-with-k-one-bits.h"

#include <string>
#include <vector>

namespace leetcode::problem_3821 {

class FindNthSmallestIntegerWithKOneBitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindNthSmallestIntegerWithKOneBitsSolution solution_;
};

TEST_P(FindNthSmallestIntegerWithKOneBitsTest, Example1) {
  EXPECT_EQ(solution_.nthSmallest(4, 2), 9);
}

TEST_P(FindNthSmallestIntegerWithKOneBitsTest, Example2) {
  EXPECT_EQ(solution_.nthSmallest(3, 1), 4);
}

TEST_P(FindNthSmallestIntegerWithKOneBitsTest, SelfAuthoredSmallKOne) {
  // 第 1 个恰好有 1 个 1 的数是 1 (1_2)。
  EXPECT_EQ(solution_.nthSmallest(1, 1), 1);
  // 第 2 个恰好有 1 个 1 的数是 2 (10_2)。
  EXPECT_EQ(solution_.nthSmallest(2, 1), 2);
  // 第 5 个恰好有 1 个 1 的数是 16 (10000_2)。
  EXPECT_EQ(solution_.nthSmallest(5, 1), 16);
}

TEST_P(FindNthSmallestIntegerWithKOneBitsTest, SelfAuthoredKEqualsAllBits) {
  // 恰好有 2 个 1 的最小数是 3 (11_2)；恰好有 3 个 1 的最小数是 7 (111_2)。
  EXPECT_EQ(solution_.nthSmallest(1, 2), 3);
  EXPECT_EQ(solution_.nthSmallest(1, 3), 7);
}

TEST_P(FindNthSmallestIntegerWithKOneBitsTest, SelfAuthoredLargerN) {
  // 恰好 2 个 1 的数：3,5,6,9,10,12,17,18,20,24,...
  // 第 5 个是 10，第 10 个是 24。
  EXPECT_EQ(solution_.nthSmallest(5, 2), 10);
  EXPECT_EQ(solution_.nthSmallest(6, 2), 12);
  EXPECT_EQ(solution_.nthSmallest(10, 2), 24);
}

INSTANTIATE_TEST_SUITE_P(
    FindNthSmallestIntegerWithKOneBitsTestCases,
    FindNthSmallestIntegerWithKOneBitsTest,
    ::testing::ValuesIn(
        FindNthSmallestIntegerWithKOneBitsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3821
