#include <gtest/gtest.h>

#include "leetcode/problems/find-servers-that-handled-most-number-of-requests.h"

namespace leetcode {
namespace problem_1606 {

class FindServersThatHandledMostNumberOfRequestsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FindServersThatHandledMostNumberOfRequestsSolution solution_;
};

TEST_P(FindServersThatHandledMostNumberOfRequestsTest, Example1) {
  int k = 3;
  std::vector<int> arrival = {1, 2, 3, 4, 5};
  std::vector<int> load = {5, 2, 3, 3, 3};
  auto result = solution_.busiestServers(k, arrival, load);
  std::vector<int> expected = {1};
  EXPECT_EQ(result, expected);
}

TEST_P(FindServersThatHandledMostNumberOfRequestsTest, Example2) {
  int k = 3;
  std::vector<int> arrival = {1, 2, 3, 4};
  std::vector<int> load = {1, 2, 1, 2};
  auto result = solution_.busiestServers(k, arrival, load);
  std::vector<int> expected = {0};
  EXPECT_EQ(result, expected);
}

TEST_P(FindServersThatHandledMostNumberOfRequestsTest, Example3) {
  int k = 3;
  std::vector<int> arrival = {1, 2, 3};
  std::vector<int> load = {10, 12, 11};
  auto result = solution_.busiestServers(k, arrival, load);
  std::vector<int> expected = {0, 1, 2};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, FindServersThatHandledMostNumberOfRequestsTest,
    testing::ValuesIn(
        FindServersThatHandledMostNumberOfRequestsSolution().getStrategyNames()));

}  // namespace problem_1606
}  // namespace leetcode
