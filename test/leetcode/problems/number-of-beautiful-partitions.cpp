#include <gtest/gtest.h>

#include "leetcode/problems/number-of-beautiful-partitions.h"

namespace leetcode {
namespace problem_2478 {
namespace {

class NumberOfBeautifulPartitionsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfBeautifulPartitionsSolution solution_;
};

TEST_P(NumberOfBeautifulPartitionsTest, Example1) {
  EXPECT_EQ(solution_.beautifulPartitions("23542185131", 3, 2), 3);
}

TEST_P(NumberOfBeautifulPartitionsTest, Example2) {
  EXPECT_EQ(solution_.beautifulPartitions("23542185131", 3, 3), 1);
}

TEST_P(NumberOfBeautifulPartitionsTest, Example3) {
  EXPECT_EQ(solution_.beautifulPartitions("3312958", 3, 1), 1);
}

TEST_P(NumberOfBeautifulPartitionsTest, SelfAuthoredMinLengthTooLarge) {
  // k * minLength > n, impossible
  EXPECT_EQ(solution_.beautifulPartitions("23542185131", 6, 2), 0);
}

TEST_P(NumberOfBeautifulPartitionsTest, SelfAuthoredSingleSegment) {
  // k=1: the whole string must be one valid segment
  EXPECT_EQ(solution_.beautifulPartitions("2354", 1, 2), 1);
  EXPECT_EQ(solution_.beautifulPartitions("235", 1, 2), 0);  // ends with prime
  EXPECT_EQ(solution_.beautifulPartitions("123", 1, 1), 0);  // starts with non-prime
}

TEST_P(NumberOfBeautifulPartitionsTest, SelfAuthoredAllPrimeDigits) {
  // No non-prime digit to end a segment
  EXPECT_EQ(solution_.beautifulPartitions("2357", 2, 1), 0);
}

TEST_P(NumberOfBeautifulPartitionsTest, SelfAuthoredExactFit) {
  // Each segment exactly minLength, and alternating prime/non-prime works
  // "21|31"  -> k=2, minLength=2, both segments start with prime, end with non-prime
  EXPECT_EQ(solution_.beautifulPartitions("2131", 2, 2), 1);
}

TEST_P(NumberOfBeautifulPartitionsTest, SelfAuthoredStressSmall) {
  // A case with multiple valid splits
  // s="2121", k=2, minLength=1
  // Valid segments: "2"|"121" (but "121" ends with non-prime? "121" ends with '1' non-prime, starts with '1' non-prime -> invalid)
  // "21"|"21" both valid
  // "212"|"1" - "212" ends with prime '2' invalid
  // So only 1 way
  EXPECT_EQ(solution_.beautifulPartitions("2121", 2, 1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfBeautifulPartitionsTest,
    testing::ValuesIn(
        NumberOfBeautifulPartitionsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2478
}  // namespace leetcode
