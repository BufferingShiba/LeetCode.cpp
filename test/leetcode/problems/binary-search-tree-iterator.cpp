#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/binary-search-tree-iterator.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_173 {

class BinarySearchTreeIteratorTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

//! Official example 1: [7, 3, 15, null, null, 9, 20]
TEST_P(BinarySearchTreeIteratorTest, OfficialExample1) {
  TreeNode* root =
      constructTree(std::vector<std::optional<int>>{
          7, 3, 15, std::nullopt, std::nullopt, 9, 20});
  {
    BinarySearchTreeIterator it(root);
    EXPECT_EQ(3, it.next());   // smallest element
    EXPECT_EQ(7, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(9, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(15, it.next());
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(20, it.next());
    EXPECT_FALSE(it.hasNext());
  }
  delete root;
}

//! Single-node tree: iterator should yield exactly one value.
TEST_P(BinarySearchTreeIteratorTest, SelfAuthoredSingleNode) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{5});
  {
    BinarySearchTreeIterator it(root);
    EXPECT_TRUE(it.hasNext());
    EXPECT_EQ(5, it.next());
    EXPECT_FALSE(it.hasNext());
  }
  delete root;
}

//! Right-skewed tree: [1, null, 2, null, 3]
TEST_P(BinarySearchTreeIteratorTest, SelfAuthoredRightSkewed) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      1, std::nullopt, 2, std::nullopt, 3});
  {
    BinarySearchTreeIterator it(root);
    EXPECT_EQ(1, it.next());
    EXPECT_EQ(2, it.next());
    EXPECT_EQ(3, it.next());
    EXPECT_FALSE(it.hasNext());
  }
  delete root;
}

//! Left-skewed tree: [3, 2, null, 1]
TEST_P(BinarySearchTreeIteratorTest, SelfAuthoredLeftSkewed) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{3, 2, std::nullopt, 1});
  {
    BinarySearchTreeIterator it(root);
    EXPECT_EQ(1, it.next());
    EXPECT_EQ(2, it.next());
    EXPECT_EQ(3, it.next());
    EXPECT_FALSE(it.hasNext());
  }
  delete root;
}

INSTANTIATE_TEST_SUITE_P(BinarySearchTreeIteratorParams,
                         BinarySearchTreeIteratorTest,
                         ::testing::Values(0));

}  // namespace problem_173
}  // namespace leetcode
