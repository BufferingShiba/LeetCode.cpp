#include <gtest/gtest.h>

#include "leetcode/problems/graph-connectivity-with-threshold.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1627 {
namespace {

using testing::TestWithParam;
using testing::ValuesIn;

class GraphConnectivityWithThresholdTest
    : public TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  GraphConnectivityWithThreshold solution_;
};

}  // namespace

TEST_P(GraphConnectivityWithThresholdTest, Example1) {
  int n = 6;
  int threshold = 2;
  std::vector<std::vector<int>> queries = {{1, 4}, {2, 5}, {3, 6}};
  std::vector<bool> expected = {false, false, true};
  EXPECT_EQ(solution_.areConnected(n, threshold, queries), expected);
}

TEST_P(GraphConnectivityWithThresholdTest, Example2) {
  int n = 6;
  int threshold = 0;
  std::vector<std::vector<int>> queries = {{4, 5}, {3, 4}, {3, 2}, {2, 6}, {1, 3}};
  std::vector<bool> expected = {true, true, true, true, true};
  EXPECT_EQ(solution_.areConnected(n, threshold, queries), expected);
}

TEST_P(GraphConnectivityWithThresholdTest, Example3) {
  int n = 5;
  int threshold = 1;
  std::vector<std::vector<int>> queries = {{4, 5}, {4, 5}, {3, 2}, {2, 3}, {3, 4}};
  std::vector<bool> expected = {false, false, false, false, false};
  EXPECT_EQ(solution_.areConnected(n, threshold, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    GraphConnectivityWithThresholdTestSuite,
    GraphConnectivityWithThresholdTest,
    ValuesIn(GraphConnectivityWithThreshold().getStrategyNames()));

}  // namespace problem_1627
}  // namespace leetcode
