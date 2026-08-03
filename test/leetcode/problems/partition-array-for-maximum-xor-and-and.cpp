#include "leetcode/problems/partition-array-for-maximum-xor-and-and.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3630 {

namespace {

std::vector<int> makeVector(std::initializer_list<int> il) {
  return std::vector<int>(il);
}

}  // namespace

class PartitionArrayForMaximumXorAndAndTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  PartitionArrayForMaximumXorAndAndSolution solution;
};

TEST_P(PartitionArrayForMaximumXorAndAndTest, Example1) {
  auto nums = makeVector({2, 3});
  EXPECT_EQ(solution.maximizeXorAndXor(nums), 5);
}

TEST_P(PartitionArrayForMaximumXorAndAndTest, Example2) {
  auto nums = makeVector({1, 3, 2});
  EXPECT_EQ(solution.maximizeXorAndXor(nums), 6);
}

TEST_P(PartitionArrayForMaximumXorAndAndTest, Example3) {
  auto nums = makeVector({2, 3, 6, 7});
  EXPECT_EQ(solution.maximizeXorAndXor(nums), 15);
}

TEST_P(PartitionArrayForMaximumXorAndAndTest, SelfAuthoredSingleElement) {
  auto nums = makeVector({42});
  // One element: put it in A (or C) -> XOR=42, or in B -> AND=42.
  EXPECT_EQ(solution.maximizeXorAndXor(nums), 42);
}

TEST_P(PartitionArrayForMaximumXorAndAndTest, SelfAuthoredSingleElementOne) {
  auto nums = makeVector({1});
  EXPECT_EQ(solution.maximizeXorAndXor(nums), 1);
}

TEST_P(PartitionArrayForMaximumXorAndAndTest, SelfAuthoredTwoEqual) {
  auto nums = makeVector({5, 5});
  // Options: put both in B -> AND=5, XOR(A)+XOR(C)=0 -> 5.
  // Put both in A -> XOR=0. Put one each -> 5+5=10.
  // Max = 5 (B) + (5 in A,5 in C -> XOR(A)=5,XOR(C)=5 -> 10)? total 15? No,
  // A={5},C={5}: XOR(A)=5+XOR(C)=5=10, AND(B)=0 (empty) -> 10.
  EXPECT_EQ(solution.maximizeXorAndXor(nums), 10);
}

INSTANTIATE_TEST_SUITE_P(
    PartitionArrayForMaximumXorAndAndTestSuite,
    PartitionArrayForMaximumXorAndAndTest,
    ::testing::ValuesIn(
        PartitionArrayForMaximumXorAndAndSolution().getStrategyNames()));

}  // namespace problem_3630
}  // namespace leetcode
