#include <gtest/gtest.h>

#include "leetcode/problems/range-sum-query-2d-immutable.h"

namespace leetcode {
namespace problem_304 {

class RangeSumQuery2dImmutableTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(RangeSumQuery2dImmutableTest, Example1) {
  std::vector<std::vector<int>> matrix = {
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}};
  NumMatrix obj(matrix);
  EXPECT_EQ(8, obj.sumRegion(2, 1, 4, 3));
  EXPECT_EQ(11, obj.sumRegion(1, 1, 2, 2));
  EXPECT_EQ(12, obj.sumRegion(1, 2, 2, 4));
}

TEST_P(RangeSumQuery2dImmutableTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> matrix = {{5}};
  NumMatrix obj(matrix);
  EXPECT_EQ(5, obj.sumRegion(0, 0, 0, 0));
}

TEST_P(RangeSumQuery2dImmutableTest, SelfAuthoredFullMatrix) {
  std::vector<std::vector<int>> matrix = {
      {1, 2},
      {3, 4}};
  NumMatrix obj(matrix);
  EXPECT_EQ(10, obj.sumRegion(0, 0, 1, 1));
}

INSTANTIATE_TEST_SUITE_P(RangeSumQuery2dImmutableTestSuite,
                         RangeSumQuery2dImmutableTest, ::testing::Values(0));

}  // namespace problem_304
}  // namespace leetcode
