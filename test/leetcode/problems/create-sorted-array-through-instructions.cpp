#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/create-sorted-array-through-instructions.h"

namespace leetcode {
namespace problem_1649 {

class CreateSortedArrayThroughInstructionsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CreateSortedArrayThroughInstructionsSolution solution_;
};

TEST_P(CreateSortedArrayThroughInstructionsTest, Example1) {
  std::vector<int> instructions = {1, 5, 6, 2};
  EXPECT_EQ(solution_.createSortedArray(instructions), 1);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, Example2) {
  std::vector<int> instructions = {1, 2, 3, 6, 5, 4};
  EXPECT_EQ(solution_.createSortedArray(instructions), 3);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, Example3) {
  std::vector<int> instructions = {1, 3, 3, 3, 2, 4, 2, 1, 2};
  EXPECT_EQ(solution_.createSortedArray(instructions), 4);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, SelfAuthoredSingleElement) {
  std::vector<int> instructions = {42};
  EXPECT_EQ(solution_.createSortedArray(instructions), 0);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, SelfAuthoredAllSame) {
  std::vector<int> instructions = {5, 5, 5, 5};
  EXPECT_EQ(solution_.createSortedArray(instructions), 0);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, SelfAuthoredStrictlyIncreasing) {
  std::vector<int> instructions = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.createSortedArray(instructions), 0);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, SelfAuthoredStrictlyDecreasing) {
  std::vector<int> instructions = {5, 4, 3, 2, 1};
  // Each insert: first has cost 0, second: min(0,1)=0, third: min(0,2)=0...
  // Actually let's trace:
  // Insert 5 -> cost 0, nums=[5]
  // Insert 4 -> less=0, greater=1 -> min=0, nums=[4,5]
  // Insert 3 -> less=0, greater=2 -> min=0, nums=[3,4,5]
  // Insert 2 -> less=0, greater=3 -> min=0, nums=[2,3,4,5]
  // Insert 1 -> less=0, greater=4 -> min=0, nums=[1,2,3,4,5]
  // Total = 0
  EXPECT_EQ(solution_.createSortedArray(instructions), 0);
}

TEST_P(CreateSortedArrayThroughInstructionsTest, SelfAuthoredMixed) {
  std::vector<int> instructions = {3, 1, 2};
  // Insert 3 -> cost 0, nums=[3]
  // Insert 1 -> less=0, greater=1 -> min=0, nums=[1,3]
  // Insert 2 -> less=1, greater=1 -> min=1, nums=[1,2,3]
  // Total = 1
  EXPECT_EQ(solution_.createSortedArray(instructions), 1);
}

INSTANTIATE_TEST_SUITE_P(
    , CreateSortedArrayThroughInstructionsTest,
    testing::ValuesIn(
        CreateSortedArrayThroughInstructionsSolution().getStrategyNames()));

}  // namespace problem_1649
}  // namespace leetcode
