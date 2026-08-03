#include <gtest/gtest.h>

#include <string>
#include "leetcode/problems/restore-the-array.h"

using namespace leetcode::problem_1416;
using namespace std;

class RestoreTheArrayTest : public ::testing::TestWithParam<string> {
 protected:
  RestoreTheArraySolution solution;
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(RestoreTheArrayTest, Example1) {
  EXPECT_EQ(solution.numberOfArrays("1000", 10000), 1);
}

TEST_P(RestoreTheArrayTest, Example2) {
  EXPECT_EQ(solution.numberOfArrays("1000", 10), 0);
}

TEST_P(RestoreTheArrayTest, Example3) {
  EXPECT_EQ(solution.numberOfArrays("1317", 2000), 8);
}

INSTANTIATE_TEST_SUITE_P(
    RestoreTheArray,
    RestoreTheArrayTest,
    ::testing::ValuesIn(RestoreTheArraySolution().getStrategyNames()));
