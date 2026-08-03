#include <gtest/gtest.h>

#include "leetcode/problems/number-of-recent-calls.h"

namespace leetcode::problem_933 {

class NumberOfRecentCallsTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(NumberOfRecentCallsTest, OfficialExample1) {
  RecentCounter counter;
  EXPECT_EQ(counter.ping(1), 1);
  EXPECT_EQ(counter.ping(100), 2);
  EXPECT_EQ(counter.ping(3001), 3);
  EXPECT_EQ(counter.ping(3002), 3);
}

INSTANTIATE_TEST_SUITE_P(All, NumberOfRecentCallsTest, ::testing::Values(0));

}  // namespace leetcode::problem_933
