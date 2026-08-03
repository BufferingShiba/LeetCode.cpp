#include <gtest/gtest.h>

#include "leetcode/problems/fizz-buzz.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_412 {
namespace {

class FizzBuzzTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FizzBuzzSolution solution;
};

TEST_P(FizzBuzzTest, Example1) {
  std::vector<std::string> expected = {"1", "2", "Fizz"};
  EXPECT_EQ(solution.fizzBuzz(3), expected);
}

TEST_P(FizzBuzzTest, Example2) {
  std::vector<std::string> expected = {"1", "2", "Fizz", "4", "Buzz"};
  EXPECT_EQ(solution.fizzBuzz(5), expected);
}

TEST_P(FizzBuzzTest, Example3) {
  std::vector<std::string> expected = {"1", "2", "Fizz", "4", "Buzz",
                                       "Fizz", "7", "8", "Fizz", "Buzz",
                                       "11", "Fizz", "13", "14", "FizzBuzz"};
  EXPECT_EQ(solution.fizzBuzz(15), expected);
}

TEST_P(FizzBuzzTest, SelfAuthoredSingleElement) {
  std::vector<std::string> expected = {"1"};
  EXPECT_EQ(solution.fizzBuzz(1), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FizzBuzzTestSuite, FizzBuzzTest,
    ::testing::ValuesIn(FizzBuzzSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_412
}  // namespace leetcode
