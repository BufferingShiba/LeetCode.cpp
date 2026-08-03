#include <gtest/gtest.h>

#include "leetcode/problems/count-servers-that-communicate.h"

namespace leetcode {
namespace problem_1267 {
namespace {

class CountServersThatCommunicateTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountServersThatCommunicateSolution solution_;
};

}  // namespace

TEST_P(CountServersThatCommunicateTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};
  EXPECT_EQ(solution_.countServers(grid), 0);
}

TEST_P(CountServersThatCommunicateTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 0}, {1, 1}};
  EXPECT_EQ(solution_.countServers(grid), 3);
}

TEST_P(CountServersThatCommunicateTest, Example3) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  EXPECT_EQ(solution_.countServers(grid), 4);
}

TEST_P(CountServersThatCommunicateTest, SelfAuthoredSingleServer) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(solution_.countServers(grid), 0);
}

TEST_P(CountServersThatCommunicateTest, SelfAuthoredAllInOneRow) {
  std::vector<std::vector<int>> grid = {{1, 0, 1, 1}};
  EXPECT_EQ(solution_.countServers(grid), 3);
}

INSTANTIATE_TEST_SUITE_P(
    CountServersThatCommunicateParams, CountServersThatCommunicateTest,
    ::testing::ValuesIn(
        CountServersThatCommunicateSolution().getStrategyNames()));

}  // namespace problem_1267
}  // namespace leetcode
