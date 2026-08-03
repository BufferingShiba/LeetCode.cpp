#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/open-the-lock.h"

namespace leetcode {
namespace problem_752 {

class OpenTheLockTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  OpenTheLockSolution solution;
};

TEST_P(OpenTheLockTest, Example1) {
  std::vector<std::string> deadends = {"0201", "0101", "0102", "1212",
                                        "2002"};
  EXPECT_EQ(6, solution.openLock(deadends, "0202"));
}

TEST_P(OpenTheLockTest, Example2) {
  std::vector<std::string> deadends = {"8888"};
  EXPECT_EQ(1, solution.openLock(deadends, "0009"));
}

TEST_P(OpenTheLockTest, Example3) {
  std::vector<std::string> deadends = {"8887", "8889", "8878", "8898",
                                        "8788", "8988", "7888", "9888"};
  EXPECT_EQ(-1, solution.openLock(deadends, "8888"));
}

INSTANTIATE_TEST_SUITE_P(
    OpenTheLockTestSuite, OpenTheLockTest,
    ::testing::ValuesIn(OpenTheLockSolution().getStrategyNames()));

}  // namespace problem_752
}  // namespace leetcode
