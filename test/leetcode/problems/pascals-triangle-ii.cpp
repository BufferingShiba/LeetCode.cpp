#include "leetcode/problems/pascals-triangle-ii.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_119 {
namespace {

class PascalsTriangleIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PascalsTriangleIiSolution solution_;
};

TEST_P(PascalsTriangleIiTest, Example1) {
  EXPECT_EQ((std::vector<int>{1, 3, 3, 1}), solution_.getRow(3));
}

TEST_P(PascalsTriangleIiTest, Example2) {
  EXPECT_EQ((std::vector<int>{1}), solution_.getRow(0));
}

TEST_P(PascalsTriangleIiTest, Example3) {
  EXPECT_EQ((std::vector<int>{1, 1}), solution_.getRow(1));
}

TEST_P(PascalsTriangleIiTest, SelfAuthoredRowIndex2) {
  EXPECT_EQ((std::vector<int>{1, 2, 1}), solution_.getRow(2));
}

TEST_P(PascalsTriangleIiTest, SelfAuthoredRowIndex4) {
  EXPECT_EQ((std::vector<int>{1, 4, 6, 4, 1}), solution_.getRow(4));
}

TEST_P(PascalsTriangleIiTest, SelfAuthoredRowIndex5) {
  EXPECT_EQ((std::vector<int>{1, 5, 10, 10, 5, 1}), solution_.getRow(5));
}

INSTANTIATE_TEST_SUITE_P(
    PascalsTriangleIiTestSuite, PascalsTriangleIiTest,
    ::testing::ValuesIn(PascalsTriangleIiSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_119
}  // namespace leetcode
