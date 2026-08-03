#include <gtest/gtest.h>

#include "leetcode/problems/maximum-frequency-stack.h"

using namespace leetcode::problem_895;

class MaximumFrequencyStackTest : public ::testing::TestWithParam<int> {
 protected:
  FreqStack fs;
};

TEST_P(MaximumFrequencyStackTest, Example1) {
  fs.push(5);
  fs.push(7);
  fs.push(5);
  fs.push(7);
  fs.push(4);
  fs.push(5);
  EXPECT_EQ(fs.pop(), 5);
  EXPECT_EQ(fs.pop(), 7);
  EXPECT_EQ(fs.pop(), 5);
  EXPECT_EQ(fs.pop(), 4);
}

INSTANTIATE_TEST_SUITE_P(All, MaximumFrequencyStackTest, ::testing::Values(0));
