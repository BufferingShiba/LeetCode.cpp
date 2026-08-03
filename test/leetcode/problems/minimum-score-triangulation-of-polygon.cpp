#include "leetcode/problems/minimum-score-triangulation-of-polygon.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1039 {

class MinimumScoreTriangulationOfPolygonTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumScoreTriangulationOfPolygonSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  values = [1,2,3]
// Output: 6
TEST_P(MinimumScoreTriangulationOfPolygonTest, OfficialExample1) {
  vector<int> values = {1, 2, 3};
  EXPECT_EQ(6, solution.minScoreTriangulation(values));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  values = [3,7,4,5]
// Output: 144
TEST_P(MinimumScoreTriangulationOfPolygonTest, OfficialExample2) {
  vector<int> values = {3, 7, 4, 5};
  EXPECT_EQ(144, solution.minScoreTriangulation(values));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  values = [1,3,1,4,1,5]
// Output: 13
TEST_P(MinimumScoreTriangulationOfPolygonTest, OfficialExample3) {
  vector<int> values = {1, 3, 1, 4, 1, 5};
  EXPECT_EQ(13, solution.minScoreTriangulation(values));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumScoreTriangulationOfPolygonTest,
    ::testing::ValuesIn(MinimumScoreTriangulationOfPolygonSolution().getStrategyNames()));

}  // namespace problem_1039
}  // namespace leetcode
