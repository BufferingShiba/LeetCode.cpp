#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/iterator-for-combination.h"

namespace leetcode {
namespace problem_1286 {

class IteratorForCombinationTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(IteratorForCombinationTest, Example1) {
  CombinationIterator itr("abc", 2);
  EXPECT_EQ(itr.next(), "ab");
  EXPECT_TRUE(itr.hasNext());
  EXPECT_EQ(itr.next(), "ac");
  EXPECT_TRUE(itr.hasNext());
  EXPECT_EQ(itr.next(), "bc");
  EXPECT_FALSE(itr.hasNext());
}

TEST_P(IteratorForCombinationTest, SelfAuthoredSingleCharacter) {
  CombinationIterator itr("a", 1);
  EXPECT_EQ(itr.next(), "a");
  EXPECT_FALSE(itr.hasNext());
}

TEST_P(IteratorForCombinationTest, SelfAuthoredFullLength) {
  CombinationIterator itr("abcd", 4);
  EXPECT_EQ(itr.next(), "abcd");
  EXPECT_FALSE(itr.hasNext());
}

INSTANTIATE_TEST_SUITE_P(IteratorForCombinationDesign,
                         IteratorForCombinationTest, ::testing::Values(0));

}  // namespace problem_1286
}  // namespace leetcode
