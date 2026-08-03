#include <gtest/gtest.h>

#include "leetcode/problems/maximum-score-from-grid-operations.h"

namespace leetcode::problem_3225 {

using MaximumScoreFromGridOperationsTest =
    ::testing::TestWithParam<std::string>;

class ParamSolution final
    : public MaximumScoreFromGridOperationsSolution {
 public:
  explicit ParamSolution(const std::string& name) { setStrategy(name); }
};

TEST_P(MaximumScoreFromGridOperationsTest, Example1) {
  ParamSolution s(GetParam());
  std::vector<std::vector<int>> grid = {
      {0, 0, 0, 0, 0},
      {0, 0, 3, 0, 0},
      {0, 1, 0, 0, 0},
      {5, 0, 0, 3, 0},
      {0, 0, 0, 0, 2}
  };
  EXPECT_EQ(11LL, s.maximumScore(grid));
}

TEST_P(MaximumScoreFromGridOperationsTest, Example2) {
  ParamSolution s(GetParam());
  std::vector<std::vector<int>> grid = {
      {10, 9, 0, 0, 15},
      {7, 1, 0, 8, 0},
      {5, 20, 0, 11, 0},
      {0, 0, 0, 1, 2},
      {8, 12, 1, 10, 3}
  };
  EXPECT_EQ(94LL, s.maximumScore(grid));
}

TEST_P(MaximumScoreFromGridOperationsTest, SelfAuthoredSingleCell) {
  ParamSolution s(GetParam());
  std::vector<std::vector<int>> grid = {{7}};
  // Only one cell; painting it black yields no white-with-black-neighbor.
  EXPECT_EQ(0LL, s.maximumScore(grid));
}

// SelfAuthored: brute-force cross-check against Examples 1 and 2.
// Brute force enumerates all height vectors and scores every column only after
// both neighbours are known.
TEST_P(MaximumScoreFromGridOperationsTest, SelfAuthoredBruteForceCheck) {
  std::vector<std::vector<int>> grids[] = {
      {{0, 0, 0, 0, 0},
       {0, 0, 3, 0, 0},
       {0, 1, 0, 0, 0},
       {5, 0, 0, 3, 0},
       {0, 0, 0, 0, 2}},
      {{10, 9, 0, 0, 15},
       {7, 1, 0, 8, 0},
       {5, 20, 0, 11, 0},
       {0, 0, 0, 1, 2},
       {8, 12, 1, 10, 3}},
      {{1, 2},
       {3, 4}},
      {{0}},
      {{5, 5},
       {5, 5}}
  };
  for (auto& grid : grids) {
    const int n = (int)grid.size();
    long long best = 0;
    std::vector<int> h(n, 0);
    std::function<void(int)> rec = [&](int c) {
      if (c == n) {
        long long total = 0;
        for (int col = 0; col < n; ++col) {
          int hl = (col > 0) ? h[col - 1] : 0;
          int hr = (col + 1 < n) ? h[col + 1] : 0;
          int M = std::max(hl, hr);
          if (M > h[col]) {
            for (int r = h[col]; r < M; ++r) total += grid[r][col];
          }
        }
        best = std::max(best, total);
        return;
      }
      for (int hv = 0; hv <= n; ++hv) { h[c] = hv; rec(c + 1); }
    };
    rec(0);
    ParamSolution s(GetParam());
    EXPECT_EQ(best, s.maximumScore(grid));
  }
}

INSTANTIATE_TEST_SUITE_P(
    MaximumScoreFromGridOperationsTestSuite,
    MaximumScoreFromGridOperationsTest,
    ::testing::ValuesIn(
        MaximumScoreFromGridOperationsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3225
