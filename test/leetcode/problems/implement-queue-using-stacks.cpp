#include <gtest/gtest.h>

#include "leetcode/problems/implement-queue-using-stacks.h"

using leetcode::problem_232::MyQueue;

namespace {

class ImplementQueueUsingStacksTest : public ::testing::TestWithParam<int> {};

TEST_P(ImplementQueueUsingStacksTest, ExampleOfficialCase) {
  // ["MyQueue", "push", "push", "peek", "pop", "empty"]
  // [[], [1], [2], [], [], []]
  // Output [null, null, null, 1, 1, false]
  MyQueue myQueue;
  myQueue.push(1);
  myQueue.push(2);
  EXPECT_EQ(myQueue.peek(), 1);
  EXPECT_EQ(myQueue.pop(), 1);
  EXPECT_FALSE(myQueue.empty());
}

TEST_P(ImplementQueueUsingStacksTest, SelfAuthoredMultipleBatchTransfer) {
  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);
  EXPECT_EQ(q.pop(), 1);
  q.push(4);
  q.push(5);
  EXPECT_EQ(q.peek(), 2);
  EXPECT_EQ(q.pop(), 2);
  EXPECT_EQ(q.pop(), 3);
  EXPECT_EQ(q.pop(), 4);
  EXPECT_EQ(q.pop(), 5);
  EXPECT_TRUE(q.empty());
}

TEST_P(ImplementQueueUsingStacksTest, SelfAuthoredEmptyLifecycle) {
  MyQueue q;
  EXPECT_TRUE(q.empty());
  q.push(7);
  EXPECT_FALSE(q.empty());
  EXPECT_EQ(q.peek(), 7);
  EXPECT_EQ(q.pop(), 7);
  EXPECT_TRUE(q.empty());
}

INSTANTIATE_TEST_SUITE_P(ImplementQueueUsingStacksTestGroup,
                         ImplementQueueUsingStacksTest, ::testing::Values(0));

}  // namespace
