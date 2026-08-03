#include <gtest/gtest.h>

#include "leetcode/problems/lfu-cache.h"

namespace leetcode {
namespace problem_460 {

class LfuCacheTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(LfuCacheTest, Example1) {
  LFUCache lfu(2);
  lfu.put(1, 1);
  lfu.put(2, 2);
  EXPECT_EQ(lfu.get(1), 1);
  lfu.put(3, 3);
  EXPECT_EQ(lfu.get(2), -1);
  EXPECT_EQ(lfu.get(3), 3);
  lfu.put(4, 4);
  EXPECT_EQ(lfu.get(1), -1);
  EXPECT_EQ(lfu.get(3), 3);
  EXPECT_EQ(lfu.get(4), 4);
}

TEST_P(LfuCacheTest, SelfAuthoredCapacityOne) {
  LFUCache lfu(1);
  lfu.put(2, 1);
  EXPECT_EQ(lfu.get(2), 1);
  lfu.put(3, 2);
  EXPECT_EQ(lfu.get(2), -1);
  EXPECT_EQ(lfu.get(3), 2);
}

TEST_P(LfuCacheTest, SelfAuthoredUpdateSameKey) {
  LFUCache lfu(2);
  lfu.put(1, 1);
  lfu.put(2, 2);
  lfu.put(1, 10);  // update key 1
  EXPECT_EQ(lfu.get(1), 10);
  EXPECT_EQ(lfu.get(2), 2);
}

INSTANTIATE_TEST_SUITE_P(
    LfuCacheTests,
    LfuCacheTest,
    ::testing::Values(0));

}  // namespace problem_460
}  // namespace leetcode
