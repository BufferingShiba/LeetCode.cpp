#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/coordinate-with-maximum-network-quality.h"

namespace leetcode {
namespace problem_1620 {

class CoordinateWithMaximumNetworkQualityTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CoordinateWithMaximumNetworkQualitySolution solution;
};

TEST_P(CoordinateWithMaximumNetworkQualityTest, Example1) {
  std::vector<std::vector<int>> towers = {{1, 2, 5}, {2, 1, 7}, {3, 1, 9}};
  int radius = 2;
  std::vector<int> expected = {2, 1};
  EXPECT_EQ(solution.bestCoordinate(towers, radius), expected);
}

TEST_P(CoordinateWithMaximumNetworkQualityTest, Example2) {
  std::vector<std::vector<int>> towers = {{23, 11, 21}};
  int radius = 9;
  std::vector<int> expected = {23, 11};
  EXPECT_EQ(solution.bestCoordinate(towers, radius), expected);
}

TEST_P(CoordinateWithMaximumNetworkQualityTest, Example3) {
  std::vector<std::vector<int>> towers = {{1, 2, 13}, {2, 1, 7}, {0, 1, 9}};
  int radius = 2;
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(solution.bestCoordinate(towers, radius), expected);
}

TEST_P(CoordinateWithMaximumNetworkQualityTest, SelfAuthoredLexicographicallyMinTie) {
  // 两个点质量相同，应选 x,y 更小的坐标
  std::vector<std::vector<int>> towers = {{0, 0, 10}};
  int radius = 1;
  // 可达点 (0,0) d=0 -> 10; (1,0) d=1 -> 5; (0,1) d=1 ->5; (1,1) d=sqrt2>1 不可达
  std::vector<int> expected = {0, 0};
  EXPECT_EQ(solution.bestCoordinate(towers, radius), expected);
}

INSTANTIATE_TEST_SUITE_P(
    CoordinateWithMaximumNetworkQualityTestSuite,
    CoordinateWithMaximumNetworkQualityTest,
    ::testing::ValuesIn(
        CoordinateWithMaximumNetworkQualitySolution().getStrategyNames()));

}  // namespace problem_1620
}  // namespace leetcode
