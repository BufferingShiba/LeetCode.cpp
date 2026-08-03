#include "leetcode/problems/split-array-into-fibonacci-sequence.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_842 {
namespace {

bool isFibonacciLike(const std::vector<int>& seq) {
  if (seq.size() < 3) return false;
  for (size_t i = 0; i + 2 < seq.size(); ++i) {
    if (static_cast<long long>(seq[i]) + seq[i + 1] != seq[i + 2]) {
      return false;
    }
  }
  return true;
}

bool isSplitValid(const std::string& num, const std::vector<int>& seq) {
  if (seq.empty()) return num.empty();
  std::string built;
  for (size_t i = 0; i < seq.size(); ++i) {
    built += std::to_string(seq[i]);
  }
  return built == num;
}

}  // namespace

class SplitArrayIntoFibonacciSequenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SplitArrayIntoFibonacciSequenceSolution solution;
};

TEST_P(SplitArrayIntoFibonacciSequenceTest, Example1) {
  auto res = solution.splitIntoFibonacci("1101111");
  EXPECT_TRUE(isFibonacciLike(res));
  EXPECT_TRUE(isSplitValid("1101111", res));
}

TEST_P(SplitArrayIntoFibonacciSequenceTest, Example2) {
  auto res = solution.splitIntoFibonacci("112358130");
  EXPECT_TRUE(res.empty());
}

TEST_P(SplitArrayIntoFibonacciSequenceTest, Example3) {
  auto res = solution.splitIntoFibonacci("0123");
  EXPECT_TRUE(res.empty());
}

TEST_P(SplitArrayIntoFibonacciSequenceTest, Example4) {
  auto res = solution.splitIntoFibonacci("123456579");
  EXPECT_TRUE(isFibonacciLike(res));
  EXPECT_TRUE(isSplitValid("123456579", res));
}

TEST_P(SplitArrayIntoFibonacciSequenceTest, ShortTwoNumbersOnly) {
  auto res = solution.splitIntoFibonacci("12");
  EXPECT_TRUE(res.empty());  // 不足 3 个数
}

TEST_P(SplitArrayIntoFibonacciSequenceTest, AllZero) {
  auto res = solution.splitIntoFibonacci("000");
  ASSERT_TRUE(isFibonacciLike(res));
  EXPECT_TRUE(isSplitValid("000", res));
}

TEST_P(SplitArrayIntoFibonacciSequenceTest, SingleDigit) {
  auto res = solution.splitIntoFibonacci("5");
  EXPECT_TRUE(res.empty());
}

INSTANTIATE_TEST_SUITE_P(
    SplitArrayIntoFibonacciSequenceTestSuite,
    SplitArrayIntoFibonacciSequenceTest,
    ::testing::ValuesIn(
        SplitArrayIntoFibonacciSequenceSolution().getStrategyNames()));

}  // namespace problem_842
}  // namespace leetcode
