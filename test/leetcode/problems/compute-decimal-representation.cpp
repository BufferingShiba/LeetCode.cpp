#include <gtest/gtest.h>
#include "leetcode/problems/compute-decimal-representation.h"
#include <vector>
#include <string>

namespace leetcode::problem_3697 {

class ComputeDecimalRepresentationTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ComputeDecimalRepresentationSolution solution;
};

TEST_P(ComputeDecimalRepresentationTest, Example1) {
  EXPECT_EQ(solution.decimalRepresentation(537),
            std::vector<int>({500, 30, 7}));
}

TEST_P(ComputeDecimalRepresentationTest, Example2) {
  EXPECT_EQ(solution.decimalRepresentation(102),
            std::vector<int>({100, 2}));
}

TEST_P(ComputeDecimalRepresentationTest, Example3) {
  EXPECT_EQ(solution.decimalRepresentation(6),
            std::vector<int>({6}));
}

TEST_P(ComputeDecimalRepresentationTest, SelfAuthoredLarge) {
  EXPECT_EQ(solution.decimalRepresentation(900000000),
            std::vector<int>({900000000}));
}

TEST_P(ComputeDecimalRepresentationTest, SelfAuthoredMixed) {
  EXPECT_EQ(solution.decimalRepresentation(1000000000),
            std::vector<int>({1000000000}));
}

INSTANTIATE_TEST_SUITE_P(
    ComputeDecimalRepresentationTestSuite,
    ComputeDecimalRepresentationTest,
    ::testing::ValuesIn(
        ComputeDecimalRepresentationSolution().getStrategyNames()));

}  // namespace leetcode::problem_3697
