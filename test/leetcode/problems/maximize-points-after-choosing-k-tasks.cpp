#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/maximize-points-after-choosing-k-tasks.h"

namespace leetcode::problem_3767 {

class MaximizePointsAfterChoosingKTasksTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximizePointsAfterChoosingKTasksSolution solution;
};

TEST_P(MaximizePointsAfterChoosingKTasksTest, Example1) {
  std::vector<int> t1 = {5, 2, 10};
  std::vector<int> t2 = {10, 3, 8};
  int k = 2;
  EXPECT_EQ(solution.maxPoints(t1, t2, k), 22);
}

TEST_P(MaximizePointsAfterChoosingKTasksTest, Example2) {
  std::vector<int> t1 = {10, 20, 30};
  std::vector<int> t2 = {5, 15, 25};
  int k = 2;
  EXPECT_EQ(solution.maxPoints(t1, t2, k), 60);
}

TEST_P(MaximizePointsAfterChoosingKTasksTest, Example3) {
  std::vector<int> t1 = {1, 2, 3};
  std::vector<int> t2 = {4, 5, 6};
  int k = 0;
  EXPECT_EQ(solution.maxPoints(t1, t2, k), 15);
}

TEST_P(MaximizePointsAfterChoosingKTasksTest, SelfAuthoredAllTechnique1) {
  // k = n，所有任务必须用 technique1
  std::vector<int> t1 = {7, 3, 9};
  std::vector<int> t2 = {100, 200, 300};
  int k = 3;
  EXPECT_EQ(solution.maxPoints(t1, t2, k), 7 + 3 + 9);
}

TEST_P(MaximizePointsAfterChoosingKTasksTest, SelfAuthoredSingleTask) {
  std::vector<int> t1 = {42};
  std::vector<int> t2 = {99};
  // k = 1: 必须选 technique1
  EXPECT_EQ(solution.maxPoints(t1, t2, 1), 42);
  // k = 0: 选 technique2 更优
  EXPECT_EQ(solution.maxPoints(t1, t2, 0), 99);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximizePointsAfterChoosingKTasksTest,
    ::testing::ValuesIn(
        MaximizePointsAfterChoosingKTasksSolution().getStrategyNames()));

}  // namespace leetcode::problem_3767
