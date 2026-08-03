#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/ant-on-the-boundary.h"

namespace leetcode {
namespace problem_3028 {

class AntOnTheBoundaryTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  AntOnTheBoundarySolution solution_;
};

TEST_P(AntOnTheBoundaryTest, Example1) {
  std::vector<int> nums = {2, 3, -5};
  EXPECT_EQ(solution_.returnToBoundaryCount(nums), 1);
}

TEST_P(AntOnTheBoundaryTest, Example2) {
  std::vector<int> nums = {3, 2, -3, -4};
  EXPECT_EQ(solution_.returnToBoundaryCount(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    AntOnTheBoundaryTest,
    ::testing::ValuesIn(AntOnTheBoundarySolution().getStrategyNames()));

}  // namespace problem_3028
}  // namespace leetcode
