#include "leetcode/problems/sort-the-matrix-diagonally.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1329 {

class SortTheMatrixDiagonallyTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortTheMatrixDiagonallySolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
TEST_P(SortTheMatrixDiagonallyTest, OfficialExample1) {
  std::vector<std::vector<int>> mat = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
  std::vector<std::vector<int>> expected = {{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}};
  EXPECT_EQ(expected, solution.diagonalSort(mat));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
// Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
TEST_P(SortTheMatrixDiagonallyTest, OfficialExample2) {
  std::vector<std::vector<int>> mat = {
      {11, 25, 66, 1, 69, 7},
      {23, 55, 17, 45, 15, 52},
      {75, 31, 36, 44, 58, 8},
      {22, 27, 33, 25, 68, 4},
      {84, 28, 14, 11, 5, 50}};
  std::vector<std::vector<int>> expected = {
      {5, 17, 4, 1, 52, 7},
      {11, 11, 25, 45, 8, 69},
      {14, 23, 25, 44, 58, 15},
      {22, 27, 31, 36, 50, 66},
      {84, 28, 75, 33, 55, 68}};
  EXPECT_EQ(expected, solution.diagonalSort(mat));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SortTheMatrixDiagonallyTest,
    ::testing::ValuesIn(SortTheMatrixDiagonallySolution().getStrategyNames()));

}  // namespace problem_1329
}  // namespace leetcode
