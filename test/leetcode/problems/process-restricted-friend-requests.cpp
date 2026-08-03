#include "leetcode/problems/process-restricted-friend-requests.h"

#include <gtest/gtest.h>

namespace leetcode::problem_2076 {

class ProcessRestrictedFriendRequestsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  ProcessRestrictedFriendRequestsSolution solution_;
};

TEST_P(ProcessRestrictedFriendRequestsTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> restrictions = {{0, 1}};
  std::vector<std::vector<int>> requests = {{0, 2}, {2, 1}};
  auto expected = std::vector<bool>{true, false};
  EXPECT_EQ(solution_.friendRequests(n, restrictions, requests), expected);
}

TEST_P(ProcessRestrictedFriendRequestsTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> restrictions = {{0, 1}};
  std::vector<std::vector<int>> requests = {{1, 2}, {0, 2}};
  auto expected = std::vector<bool>{true, false};
  EXPECT_EQ(solution_.friendRequests(n, restrictions, requests), expected);
}

TEST_P(ProcessRestrictedFriendRequestsTest, Example3) {
  int n = 5;
  std::vector<std::vector<int>> restrictions = {{0, 1}, {1, 2}, {2, 3}};
  std::vector<std::vector<int>> requests = {{0, 4}, {1, 2}, {3, 1}, {3, 4}};
  auto expected = std::vector<bool>{true, false, true, false};
  EXPECT_EQ(solution_.friendRequests(n, restrictions, requests), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ProcessRestrictedFriendRequestsTestSuites,
    ProcessRestrictedFriendRequestsTest,
    ::testing::ValuesIn(
        ProcessRestrictedFriendRequestsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2076
