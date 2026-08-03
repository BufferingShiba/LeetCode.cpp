#include <gtest/gtest.h>

#include "leetcode/problems/insert-delete-getrandom-o1.h"

using namespace leetcode::problem_380;

class InsertDeleteGetrandomO1Test : public ::testing::TestWithParam<int> {
 protected:
  RandomizedSet rs;
};

TEST_P(InsertDeleteGetrandomO1Test, Example1) {
  // From LeetCode example
  EXPECT_TRUE(rs.insert(1));
  EXPECT_FALSE(rs.remove(2));
  EXPECT_TRUE(rs.insert(2));
  int r1 = rs.getRandom();
  EXPECT_TRUE(r1 == 1 || r1 == 2);
  EXPECT_TRUE(rs.remove(1));
  EXPECT_FALSE(rs.insert(2));
  int r2 = rs.getRandom();
  EXPECT_EQ(r2, 2);
}

TEST_P(InsertDeleteGetrandomO1Test, SelfAuthoredSingleElement) {
  EXPECT_TRUE(rs.insert(42));
  EXPECT_EQ(rs.getRandom(), 42);
  EXPECT_TRUE(rs.remove(42));
  EXPECT_FALSE(rs.remove(42));
}

TEST_P(InsertDeleteGetrandomO1Test, SelfAuthoredDuplicateInsert) {
  EXPECT_TRUE(rs.insert(7));
  EXPECT_FALSE(rs.insert(7));
}

TEST_P(InsertDeleteGetrandomO1Test, SelfAuthoredRemoveAndGetRandom) {
  EXPECT_TRUE(rs.insert(10));
  EXPECT_TRUE(rs.insert(20));
  EXPECT_TRUE(rs.remove(10));
  int r = rs.getRandom();
  EXPECT_EQ(r, 20);
}

TEST_P(InsertDeleteGetrandomO1Test, SelfAuthoredRemoveLast) {
  // Remove the only element, then verify empty state indirectly
  EXPECT_TRUE(rs.insert(100));
  EXPECT_TRUE(rs.remove(100));
  EXPECT_FALSE(rs.remove(100));
  EXPECT_TRUE(rs.insert(200));
  EXPECT_EQ(rs.getRandom(), 200);
}

INSTANTIATE_TEST_SUITE_P(
    InsertDeleteGetrandomO1Tests,
    InsertDeleteGetrandomO1Test,
    ::testing::Values(0)
);
