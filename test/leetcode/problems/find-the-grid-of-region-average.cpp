#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-grid-of-region-average.h"

namespace leetcode {
namespace problem_3030 {
namespace {

class FindTheGridOfRegionAverageTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheGridOfRegionAverageSolution solution;
};

TEST_P(FindTheGridOfRegionAverageTest, Example1) {
  std::vector<std::vector<int>> image = {{5, 6, 7, 10},
                                         {8, 9, 10, 10},
                                         {11, 12, 13, 10}};
  int threshold = 3;
  std::vector<std::vector<int>> expected = {{9, 9, 9, 9},
                                            {9, 9, 9, 9},
                                            {9, 9, 9, 9}};
  EXPECT_EQ(solution.resultGrid(image, threshold), expected);
}

TEST_P(FindTheGridOfRegionAverageTest, Example2) {
  std::vector<std::vector<int>> image = {{10, 20, 30},
                                         {15, 25, 35},
                                         {20, 30, 40},
                                         {25, 35, 45}};
  int threshold = 12;
  std::vector<std::vector<int>> expected = {{25, 25, 25},
                                            {27, 27, 27},
                                            {27, 27, 27},
                                            {30, 30, 30}};
  EXPECT_EQ(solution.resultGrid(image, threshold), expected);
}

TEST_P(FindTheGridOfRegionAverageTest, Example3) {
  std::vector<std::vector<int>> image = {{5, 6, 7},
                                         {8, 9, 10},
                                         {11, 12, 13}};
  int threshold = 1;
  std::vector<std::vector<int>> expected = {{5, 6, 7},
                                            {8, 9, 10},
                                            {11, 12, 13}};
  EXPECT_EQ(solution.resultGrid(image, threshold), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheGridOfRegionAverageTests, FindTheGridOfRegionAverageTest,
    ::testing::ValuesIn(FindTheGridOfRegionAverageSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3030
}  // namespace leetcode
