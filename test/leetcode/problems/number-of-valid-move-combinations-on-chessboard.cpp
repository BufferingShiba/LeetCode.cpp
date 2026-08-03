#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-valid-move-combinations-on-chessboard.h"

namespace leetcode {
namespace problem_2056 {
namespace {

using Sol = NumberOfValidMoveCombinationsOnChessboardSolution;

class NumberOfValidMoveCombinationsOnChessboardTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { instance.setStrategy(GetParam()); }
  Sol instance;
};

TEST_P(NumberOfValidMoveCombinationsOnChessboardTest, Example1) {
  std::vector<std::string> pieces = {"rook"};
  std::vector<std::vector<int>> positions = {{1, 1}};
  EXPECT_EQ(instance.countCombinations(pieces, positions), 15);
}

TEST_P(NumberOfValidMoveCombinationsOnChessboardTest, Example2) {
  std::vector<std::string> pieces = {"queen"};
  std::vector<std::vector<int>> positions = {{1, 1}};
  EXPECT_EQ(instance.countCombinations(pieces, positions), 22);
}

TEST_P(NumberOfValidMoveCombinationsOnChessboardTest, Example3) {
  std::vector<std::string> pieces = {"bishop"};
  std::vector<std::vector<int>> positions = {{4, 3}};
  EXPECT_EQ(instance.countCombinations(pieces, positions), 12);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfValidMoveCombinationsOnChessboardTests,
    NumberOfValidMoveCombinationsOnChessboardTest,
    ::testing::ValuesIn(Sol().getStrategyNames()));

}  // namespace
}  // namespace problem_2056
}  // namespace leetcode
