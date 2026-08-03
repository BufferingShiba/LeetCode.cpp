#include "leetcode/problems/maximum-number-of-achievable-transfer-requests.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1601 {

using Solution = MaximumNumberOfAchievableTransferRequestsSolution;

class MaximumNumberOfAchievableTransferRequestsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  Solution solution_;
};

TEST_P(MaximumNumberOfAchievableTransferRequestsTest, Example1) {
  int n = 5;
  std::vector<std::vector<int>> requests = {{0, 1}, {1, 0}, {0, 1},
                                            {1, 2}, {2, 0}, {3, 4}};
  EXPECT_EQ(5, solution_.maximumRequests(n, requests));
}

TEST_P(MaximumNumberOfAchievableTransferRequestsTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> requests = {{0, 0}, {1, 2}, {2, 1}};
  EXPECT_EQ(3, solution_.maximumRequests(n, requests));
}

TEST_P(MaximumNumberOfAchievableTransferRequestsTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> requests = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
  EXPECT_EQ(4, solution_.maximumRequests(n, requests));
}

TEST_P(MaximumNumberOfAchievableTransferRequestsTest, SelfAuthoredAllSelfLoops) {
  int n = 2;
  std::vector<std::vector<int>> requests = {{0, 0}, {1, 1}, {0, 0}};
  EXPECT_EQ(3, solution_.maximumRequests(n, requests));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfAchievableTransferRequestsTestSuite,
    MaximumNumberOfAchievableTransferRequestsTest,
    ::testing::ValuesIn(Solution().getStrategyNames()));

}  // namespace problem_1601
}  // namespace leetcode
