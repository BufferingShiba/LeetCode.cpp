#include "leetcode/problems/grumpy-bookstore-owner.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1052 {

class GrumpyBookstoreOwnerTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GrumpyBookstoreOwnerSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16
TEST_P(GrumpyBookstoreOwnerTest, OfficialExample1) {
  vector<int> customers = {1,0,1,2,1,1,7,5};
  vector<int> grumpy = {0,1,0,1,0,1,0,1};
  int minutes = 3;
  EXPECT_EQ(16, solution.maxSatisfied(customers, grumpy, minutes));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  customers = [1], grumpy = [0], minutes = 1
// Output: 1
TEST_P(GrumpyBookstoreOwnerTest, OfficialExample2) {
  vector<int> customers = {1};
  vector<int> grumpy = {0};
  int minutes = 1;
  EXPECT_EQ(1, solution.maxSatisfied(customers, grumpy, minutes));
}

// ===== Self Authored: window covers the entire array =====
TEST_P(GrumpyBookstoreOwnerTest, WindowCoversAll) {
  vector<int> customers = {2, 3, 4};
  vector<int> grumpy = {1, 1, 1};
  int minutes = 3;
  EXPECT_EQ(9, solution.maxSatisfied(customers, grumpy, minutes));
}

// ===== Self Authored: picking internal window =====
TEST_P(GrumpyBookstoreOwnerTest, InternalWindow) {
  vector<int> customers = {5, 1, 4, 2};
  vector<int> grumpy = {0, 1, 1, 0};
  int minutes = 2;
  // base = 5 + 2 = 7; best window positions for grumpy=1: indices 1,2 gain 1+4=5
  EXPECT_EQ(12, solution.maxSatisfied(customers, grumpy, minutes));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, GrumpyBookstoreOwnerTest,
    ::testing::ValuesIn(GrumpyBookstoreOwnerSolution().getStrategyNames()));

}  // namespace problem_1052
}  // namespace leetcode
