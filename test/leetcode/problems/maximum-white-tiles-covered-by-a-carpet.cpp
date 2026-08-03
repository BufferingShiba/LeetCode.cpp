#include <gtest/gtest.h>

#include "leetcode/problems/maximum-white-tiles-covered-by-a-carpet.h"

namespace leetcode {
namespace problem_2271 {

using TestParam = std::string;

class MaximumWhiteTilesCoveredByACarpetTest
    : public testing::TestWithParam<TestParam> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumWhiteTilesCoveredByACarpetSolution solution_;
};

TEST_P(MaximumWhiteTilesCoveredByACarpetTest, OfficialExamples) {
  // Example 1
  std::vector<std::vector<int>> tiles1 = {
      {1, 5}, {10, 11}, {12, 18}, {20, 25}, {30, 32}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles1, 10), 9);

  // Example 2
  std::vector<std::vector<int>> tiles2 = {{10, 11}, {1, 1}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles2, 2), 2);
}

TEST_P(MaximumWhiteTilesCoveredByACarpetTest, SelfAuthoredCases) {
  // 单个瓷砖，地毯比它短
  std::vector<std::vector<int>> tiles1 = {{5, 10}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles1, 3), 3);

  // 单个瓷砖，地毯比它长
  std::vector<std::vector<int>> tiles2 = {{5, 10}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles2, 100), 6);

  // 地毯覆盖所有瓷砖
  std::vector<std::vector<int>> tiles3 = {{1, 2}, {4, 5}, {7, 8}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles3, 100), 6);

  // 大间隙，中间对齐最优
  std::vector<std::vector<int>> tiles4 = {{1, 2}, {100, 101}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles4, 100), 3);

  // 地毯无法覆盖任何瓷砖（间隙太大）
  std::vector<std::vector<int>> tiles5 = {{1, 1}, {10, 10}};
  EXPECT_EQ(solution_.maximumWhiteTiles(tiles5, 1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximumWhiteTilesCoveredByACarpetTest,
    testing::ValuesIn(
        MaximumWhiteTilesCoveredByACarpetSolution().getStrategyNames()));

}  // namespace problem_2271
}  // namespace leetcode
