#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/design-circular-deque.h"

namespace leetcode {
namespace problem_641 {
namespace {

using TestParam = int;

class DesignCircularDequeTest : public ::testing::TestWithParam<TestParam> {
 protected:
  void SetUp() override { /* no per-strategy state needed */ }
};

}  // namespace

TEST_P(DesignCircularDequeTest, OfficialExample1) {
  DesignCircularDequeSolution deque(3);
  EXPECT_TRUE(deque.insertLast(1));
  EXPECT_TRUE(deque.insertLast(2));
  EXPECT_TRUE(deque.insertFront(3));
  EXPECT_FALSE(deque.insertFront(4));  // queue is full
  EXPECT_EQ(2, deque.getRear());
  EXPECT_TRUE(deque.isFull());
  EXPECT_TRUE(deque.deleteLast());
  EXPECT_TRUE(deque.insertFront(4));
  EXPECT_EQ(4, deque.getFront());
}

TEST_P(DesignCircularDequeTest, SelfAuthoredEmptyDequeOperations) {
  DesignCircularDequeSolution deque(2);
  EXPECT_TRUE(deque.isEmpty());
  EXPECT_FALSE(deque.isFull());
  EXPECT_EQ(-1, deque.getFront());
  EXPECT_EQ(-1, deque.getRear());
  EXPECT_FALSE(deque.deleteFront());
  EXPECT_FALSE(deque.deleteLast());
}

TEST_P(DesignCircularDequeTest, SelfAuthoredWrapAroundBehaviour) {
  DesignCircularDequeSolution deque(3);
  EXPECT_TRUE(deque.insertFront(1));
  EXPECT_TRUE(deque.insertFront(2));
  EXPECT_TRUE(deque.insertFront(3));
  EXPECT_EQ(3, deque.getFront());
  EXPECT_EQ(1, deque.getRear());
  EXPECT_TRUE(deque.isFull());
  EXPECT_TRUE(deque.deleteLast());
  EXPECT_TRUE(deque.insertLast(9));
  EXPECT_EQ(9, deque.getRear());
  EXPECT_EQ(3, deque.getFront());
}

INSTANTIATE_TEST_SUITE_P(
    DesignCircularDequeSuite, DesignCircularDequeTest,
    ::testing::Values(0),
    [](const ::testing::TestParamInfo<TestParam>& info) {
      return "SingleStrategy" + std::to_string(info.param);
    });

}  // namespace problem_641
}  // namespace leetcode
