#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/complex-number-multiplication.h"

namespace leetcode {
namespace problem_537 {

class ComplexNumberMultiplicationTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ComplexNumberMultiplicationSolution solution;
};

TEST_P(ComplexNumberMultiplicationTest, Example1) {
  EXPECT_EQ("0+2i", solution.complexNumberMultiply("1+1i", "1+1i"));
}

TEST_P(ComplexNumberMultiplicationTest, Example2) {
  EXPECT_EQ("0+-2i", solution.complexNumberMultiply("1+-1i", "1+-1i"));
}

TEST_P(ComplexNumberMultiplicationTest, MixedSigns) {
  EXPECT_EQ("97+269i", solution.complexNumberMultiply("11+-3i", "2+25i"));
}

TEST_P(ComplexNumberMultiplicationTest, ZeroRealPart) {
  EXPECT_EQ("-10+0i", solution.complexNumberMultiply("0+5i", "0+2i"));
}

TEST_P(ComplexNumberMultiplicationTest, ZeroImagpart) {
  EXPECT_EQ("6+0i", solution.complexNumberMultiply("2+0i", "3+0i"));
}

INSTANTIATE_TEST_SUITE_P(
    ComplexNumberMultiplicationTestSuite, ComplexNumberMultiplicationTest,
    ::testing::ValuesIn(ComplexNumberMultiplicationSolution().getStrategyNames()));

}  // namespace problem_537
}  // namespace leetcode
