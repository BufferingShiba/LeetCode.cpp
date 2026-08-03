#include <gtest/gtest.h>

#include "leetcode/problems/single-threaded-cpu.h"

namespace leetcode::problem_1834 {

class SingleThreadedCpuTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SingleThreadedCpuSolution solution;
};

TEST_P(SingleThreadedCpuTest, Example1) {
  std::vector<std::vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  std::vector<int> expected = {0, 2, 3, 1};
  EXPECT_EQ(solution.getOrder(tasks), expected);
}

TEST_P(SingleThreadedCpuTest, Example2) {
  std::vector<std::vector<int>> tasks = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
  std::vector<int> expected = {4, 3, 2, 0, 1};
  EXPECT_EQ(solution.getOrder(tasks), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, SingleThreadedCpuTest,
    testing::ValuesIn(SingleThreadedCpuSolution().getStrategyNames()));

}  // namespace leetcode::problem_1834
