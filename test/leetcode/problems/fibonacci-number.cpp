#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/fibonacci-number.h"

namespace leetcode {
namespace problem_509 {
namespace {

using FibonacciNumberTestParam = std::tuple<int, int>;

}  // namespace

class FibonacciNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FibonacciNumberSolution solution_;
};

TEST_P(FibonacciNumberTest, OfficialExamples) {
  const std::vector<std::tuple<int, int>> cases = {
      {2, 1},
      {3, 2},
      {4, 3},
  };

  for (const auto& [n, expected] : cases) {
    EXPECT_EQ(solution_.fib(n), expected) << "n=" << n;
  }
}

TEST_P(FibonacciNumberTest, BaseCases) {
  EXPECT_EQ(solution_.fib(0), 0);
  EXPECT_EQ(solution_.fib(1), 1);
}

TEST_P(FibonacciNumberTest, SelfAuthored) {
  EXPECT_EQ(solution_.fib(5), 5);
  EXPECT_EQ(solution_.fib(10), 55);
  EXPECT_EQ(solution_.fib(30), 832040);
}

INSTANTIATE_TEST_SUITE_P(
    FibonacciNumberTestSuite, FibonacciNumberTest,
    ::testing::ValuesIn(FibonacciNumberSolution().getStrategyNames()));

}  // namespace problem_509
}  // namespace leetcode
