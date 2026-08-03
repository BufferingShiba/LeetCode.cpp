#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/implement-trie-prefix-tree.h"

namespace leetcode {
namespace problem_208 {

class ImplementTriePrefixTreeTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { (void)GetParam(); }
};

TEST_P(ImplementTriePrefixTreeTest, OfficialExample) {
  Trie trie;
  trie.insert("apple");
  EXPECT_TRUE(trie.search("apple"));
  EXPECT_FALSE(trie.search("app"));
  EXPECT_TRUE(trie.startsWith("app"));
  trie.insert("app");
  EXPECT_TRUE(trie.search("app"));
}

TEST_P(ImplementTriePrefixTreeTest, SelfAuthoredEmptySearchAndPrefix) {
  Trie trie;
  EXPECT_FALSE(trie.search("a"));
  EXPECT_FALSE(trie.startsWith("a"));
  trie.insert("hello");
  EXPECT_TRUE(trie.search("hello"));
  EXPECT_FALSE(trie.search("hell"));
  EXPECT_TRUE(trie.startsWith("hell"));
  EXPECT_FALSE(trie.startsWith("hello!"));
}

INSTANTIATE_TEST_SUITE_P(ImplementTriePrefixTreeTests, ImplementTriePrefixTreeTest,
                         ::testing::Values(0));

}  // namespace problem_208
}  // namespace leetcode
