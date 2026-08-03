#include <gtest/gtest.h>

#include "leetcode/problems/dinner-plate-stacks.h"

namespace leetcode {
namespace problem_1172 {

TEST(DinnerPlateStacksTest, Example1) {
  DinnerPlateStacksSolution d(2);
  d.push(1);
  d.push(2);
  d.push(3);
  d.push(4);
  d.push(5);
  EXPECT_EQ(d.popAtStack(0), 2);
  d.push(20);
  d.push(21);
  EXPECT_EQ(d.popAtStack(0), 20);
  EXPECT_EQ(d.popAtStack(2), 21);
  EXPECT_EQ(d.pop(), 5);
  EXPECT_EQ(d.pop(), 4);
  EXPECT_EQ(d.pop(), 3);
  EXPECT_EQ(d.pop(), 1);
  EXPECT_EQ(d.pop(), -1);
}

TEST(DinnerPlateStacksTest, CapacityOne) {
  DinnerPlateStacksSolution d(1);
  d.push(1);
  d.push(2);
  d.push(3);
  // Stack0: [1], stack1: [2], stack2: [3]
  EXPECT_EQ(d.pop(), 3);
  // Now push should go to leftmost not-full stack (stack2 just emptied).
  d.push(4);  // stack2 gets 4
  EXPECT_EQ(d.pop(), 4);
  EXPECT_EQ(d.pop(), 2);
  EXPECT_EQ(d.pop(), 1);
  EXPECT_EQ(d.pop(), -1);
}

TEST(DinnerPlateStacksTest, PopAtMiddleCreatesGap) {
  DinnerPlateStacksSolution d(3);
  d.push(1);
  d.push(2);
  d.push(3);
  d.push(4);
  d.push(5);
  // stack0: [1,2,3], stack1: [4,5]
  EXPECT_EQ(d.popAtStack(0), 3);  // stack0: [1,2] now not-full
  d.push(6);  // goes to stack0 -> [1,2,6]
  EXPECT_EQ(d.popAtStack(0), 6);
  EXPECT_EQ(d.pop(), 5);
  EXPECT_EQ(d.popAtStack(1), 4);
  EXPECT_EQ(d.popAtStack(0), 2);
  EXPECT_EQ(d.pop(), 1);
  EXPECT_EQ(d.pop(), -1);
}

TEST(DinnerPlateStacksTest, PopAtEmptyReturnsMinusOne) {
  DinnerPlateStacksSolution d(2);
  EXPECT_EQ(d.popAtStack(0), -1);
  EXPECT_EQ(d.pop(), -1);
  d.push(10);
  EXPECT_EQ(d.popAtStack(5), -1);  // out of range
}

}  // namespace problem_1172
}  // namespace leetcode
