#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/k-closest-points-to-origin.h"

namespace leetcode {
namespace problem_973 {
namespace {

bool sameSet(const std::vector<std::vector<int>>& a,
             const std::vector<std::vector<int>>& b) {
  if (a.size() != b.size()) return false;
  auto sa = a, sb = b;
  std::sort(sa.begin(), sa.end());
  std::sort(sb.begin(), sb.end());
  return sa == sb;
}

}  // namespace

class KClosestPointsToOriginTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  KClosestPointsToOriginSolution solution_;
};

TEST_P(KClosestPointsToOriginTest, Example1) {
  std::vector<std::vector<int>> points = {{1, 3}, {-2, 2}};
  std::vector<std::vector<int>> expected = {{-2, 2}};
  auto result = solution_.kClosest(points, 1);
  EXPECT_TRUE(sameSet(result, expected));
}

TEST_P(KClosestPointsToOriginTest, Example2) {
  std::vector<std::vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  std::vector<std::vector<int>> expected = {{3, 3}, {-2, 4}};
  auto result = solution_.kClosest(points, 2);
  EXPECT_TRUE(sameSet(result, expected));
}

TEST_P(KClosestPointsToOriginTest, SelfAuthoredAllPoints) {
  std::vector<std::vector<int>> points = {{0, 1}, {1, 0}, {1, 1}, {2, 0}};
  auto result = solution_.kClosest(points, 4);
  EXPECT_TRUE(sameSet(result, points));
}

TEST_P(KClosestPointsToOriginTest, SelfAuthoredKEqualsN) {
  std::vector<std::vector<int>> points = {{-5, 0}, {0, 0}, {3, 4}};
  const auto original = points;
  auto result = solution_.kClosest(points, static_cast<int>(points.size()));
  EXPECT_TRUE(sameSet(result, original));
}

INSTANTIATE_TEST_SUITE_P(
    KClosestPointsToOriginTestSuite, KClosestPointsToOriginTest,
    ::testing::ValuesIn(KClosestPointsToOriginSolution().getStrategyNames()));

}  // namespace problem_973
}  // namespace leetcode
