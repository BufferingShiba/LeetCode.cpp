#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/kth-largest-element-in-a-stream.h"

using problem_703::KthLargest;

class KthLargestElementInAStreamTest : public ::testing::TestWithParam<int> {
};

// Scenario: reconstruct the sequence of operations as a small driver.
namespace {

struct Op {
  int val;
  int expected;
};

void RunScenario(int k, const std::vector<int>& init, const std::vector<Op>& ops) {
  KthLargest solver(k, init);
  for (const auto& op : ops) {
    EXPECT_EQ(op.expected, solver.add(op.val));
  }
}

}  // namespace

TEST_P(KthLargestElementInAStreamTest, Example1) {
  RunScenario(3, {4, 5, 8, 2}, {{3, 4}, {5, 5}, {10, 5}, {9, 8}, {4, 8}});
}

TEST_P(KthLargestElementInAStreamTest, Example2) {
  RunScenario(4, {7, 7, 7, 7, 8, 3}, {{2, 7}, {10, 7}, {9, 7}, {9, 8}});
}

TEST_P(KthLargestElementInAStreamTest, SelfAuthoredSingleElementStream) {
  // k = 1 means the largest element is always the answer.
  RunScenario(1, {5}, {{3, 5}, {10, 10}, {7, 10}});
}

INSTANTIATE_TEST_SUITE_P(KthLargestElementInAStreamTests, KthLargestElementInAStreamTest,
                         ::testing::Values(0));
