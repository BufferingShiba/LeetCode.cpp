#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/implement-stack-using-queues.h"

namespace leetcode::problem_225 {

class ImplementStackUsingQueuesTest
    : public ::testing::TestWithParam<int> {};

INSTANTIATE_TEST_SUITE_P(
    ImplementStackUsingQueuesTestSuite, ImplementStackUsingQueuesTest,
    ::testing::Values(0));

TEST_P(ImplementStackUsingQueuesTest, Example1) {
  MyStack stack;
  stack.push(1);
  stack.push(2);
  EXPECT_EQ(stack.top(), 2);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_TRUE(!stack.empty());
  EXPECT_EQ(stack.pop(), 1);
  EXPECT_TRUE(stack.empty());
}

TEST_P(ImplementStackUsingQueuesTest, SelfAuthoredPushPopSequence) {
  MyStack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  EXPECT_EQ(stack.pop(), 3);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 1);
  EXPECT_TRUE(stack.empty());
}

TEST_P(ImplementStackUsingQueuesTest, SelfAuthoredMixedOperations) {
  MyStack stack;
  EXPECT_TRUE(stack.empty());
  stack.push(7);
  EXPECT_EQ(stack.top(), 7);
  stack.push(8);
  stack.push(9);
  EXPECT_EQ(stack.pop(), 9);
  EXPECT_EQ(stack.top(), 8);
  stack.push(10);
  EXPECT_EQ(stack.pop(), 10);
  EXPECT_EQ(stack.pop(), 8);
  EXPECT_EQ(stack.pop(), 7);
  EXPECT_TRUE(stack.empty());
}

}  // namespace leetcode::problem_225
