#include <gtest/gtest.h>

#include "leetcode/problems/operations-on-tree.h"

namespace leetcode {
namespace problem_1993 {

class OperationsOnTreeTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(OperationsOnTreeTest, Example1) {
  std::vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
  LockingTree lockingTree(parent);

  EXPECT_TRUE(lockingTree.lock(2, 2));
  EXPECT_FALSE(lockingTree.unlock(2, 3));
  EXPECT_TRUE(lockingTree.unlock(2, 2));
  EXPECT_TRUE(lockingTree.lock(4, 5));
  EXPECT_TRUE(lockingTree.upgrade(0, 1));
  EXPECT_FALSE(lockingTree.lock(0, 1));
}

INSTANTIATE_TEST_SUITE_P(
    OperationsOnTreeSuite,
    OperationsOnTreeTest,
    ::testing::Values(0));

}  // namespace problem_1993
}  // namespace leetcode
