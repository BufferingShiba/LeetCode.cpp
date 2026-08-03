#include "leetcode/problems/surrounded-regions.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_130 {
namespace {

std::vector<std::vector<char>> toBoard(
    const std::vector<std::vector<char>>& rows) {
  return rows;
}

bool equalBoard(const std::vector<std::vector<char>>& a,
                const std::vector<std::vector<char>>& b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (std::size_t i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

}  // namespace

class SurroundedRegionsTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  SurroundedRegionsSolution solution_;
};

TEST_P(SurroundedRegionsTest, Example1) {
  std::vector<std::vector<char>> board = {
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'O', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'}};
  std::vector<std::vector<char>> expected = {
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'X', 'X'}};
  solution_.solve(board);
  EXPECT_TRUE(equalBoard(board, expected));
}

TEST_P(SurroundedRegionsTest, Example2) {
  std::vector<std::vector<char>> board = {{'X'}};
  std::vector<std::vector<char>> expected = {{'X'}};
  solution_.solve(board);
  EXPECT_TRUE(equalBoard(board, expected));
}

TEST_P(SurroundedRegionsTest, SelfAuthoredAllOConnectedToBorder) {
  std::vector<std::vector<char>> board = {
      {'O', 'O'},
      {'O', 'O'}};
  std::vector<std::vector<char>> expected = {
      {'O', 'O'},
      {'O', 'O'}};
  solution_.solve(board);
  EXPECT_TRUE(equalBoard(board, expected));
}

TEST_P(SurroundedRegionsTest, SelfAuthoredSingleRowNoCapture) {
  std::vector<std::vector<char>> board = {
      {'X', 'O', 'X', 'O', 'X'}};
  std::vector<std::vector<char>> expected = {
      {'X', 'O', 'X', 'O', 'X'}};
  solution_.solve(board);
  EXPECT_TRUE(equalBoard(board, expected));
}

INSTANTIATE_TEST_SUITE_P(
    SurroundedRegionsTests, SurroundedRegionsTest,
    ::testing::ValuesIn(SurroundedRegionsSolution().getStrategyNames()));

}  // namespace problem_130
}  // namespace leetcode
