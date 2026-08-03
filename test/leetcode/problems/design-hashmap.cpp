#include <gtest/gtest.h>

#include "leetcode/problems/design-hashmap.h"

namespace problem_706 {

class DesignHashmapTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { param_ = GetParam(); }

  int param_;
};

TEST_P(DesignHashmapTest, Example1) {
  DesignHashmap m;
  m.put(1, 1);
  m.put(2, 2);
  EXPECT_EQ(m.get(1), 1);
  EXPECT_EQ(m.get(3), -1);
  m.put(2, 1);
  EXPECT_EQ(m.get(2), 1);
  m.remove(2);
  EXPECT_EQ(m.get(2), -1);
}

TEST_P(DesignHashmapTest, SelfAuthoredUpdateAndReinsert) {
  DesignHashmap m;
  m.put(5, 10);
  m.put(5, 20);
  EXPECT_EQ(m.get(5), 20);
  m.remove(5);
  EXPECT_EQ(m.get(5), -1);
  m.put(5, 30);
  EXPECT_EQ(m.get(5), 30);
}

TEST_P(DesignHashmapTest, SelfAuthoredZeroKey) {
  DesignHashmap m;
  EXPECT_EQ(m.get(0), -1);
  m.put(0, 42);
  EXPECT_EQ(m.get(0), 42);
  m.remove(0);
  EXPECT_EQ(m.get(0), -1);
}

INSTANTIATE_TEST_SUITE_P(DesignHashmapTestCases, DesignHashmapTest,
                         ::testing::Values(0));

}  // namespace problem_706
