#include <gtest/gtest.h>

#include "leetcode/problems/remove-methods-from-project.h"

namespace leetcode {
namespace problem_3310 {

namespace {
bool sameSet(std::vector<int> a, std::vector<int> b) {
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}
}  // namespace

class RemoveMethodsFromProjectTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveMethodsFromProjectSolution solution;
};

TEST_P(RemoveMethodsFromProjectTest, Example1) {
  int n = 4, k = 1;
  std::vector<std::vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};
  auto res = solution.getSolution()(n, k, invocations);
  EXPECT_TRUE(sameSet(res, {0, 1, 2, 3}));
}

TEST_P(RemoveMethodsFromProjectTest, Example2) {
  int n = 5, k = 0;
  std::vector<std::vector<int>> invocations = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
  auto res = solution.getSolution()(n, k, invocations);
  EXPECT_TRUE(sameSet(res, {3, 4}));
}

TEST_P(RemoveMethodsFromProjectTest, Example3) {
  int n = 3, k = 2;
  std::vector<std::vector<int>> invocations = {{1, 2}, {0, 1}, {2, 0}};
  auto res = solution.getSolution()(n, k, invocations);
  EXPECT_TRUE(sameSet(res, {}));
}

TEST_P(RemoveMethodsFromProjectTest, SelfAuthoredNoInvocations) {
  int n = 4, k = 2;
  std::vector<std::vector<int>> invocations = {};
  auto res = solution.getSolution()(n, k, invocations);
  EXPECT_TRUE(sameSet(res, {0, 1, 3}));
}

TEST_P(RemoveMethodsFromProjectTest, SelfAuthoredSingleMethod) {
  int n = 1, k = 0;
  std::vector<std::vector<int>> invocations = {};
  auto res = solution.getSolution()(n, k, invocations);
  EXPECT_TRUE(sameSet(res, {}));
}

INSTANTIATE_TEST_SUITE_P(
    RemoveMethodsFromProjectTestSuite,
    RemoveMethodsFromProjectTest,
    ::testing::ValuesIn(RemoveMethodsFromProjectSolution().getStrategyNames()));

}  // namespace problem_3310
}  // namespace leetcode
