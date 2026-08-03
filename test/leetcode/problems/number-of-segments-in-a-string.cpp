#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/number-of-segments-in-a-string.h"

namespace leetcode {
namespace problem_434 {
namespace {

class NumberOfSegmentsInAStringTest : public testing::TestWithParam<std::string> {
};

}  // namespace

TEST_P(NumberOfSegmentsInAStringTest, Example1) {
  NumberOfSegmentsInAStringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.countSegments("Hello, my name is John"), 5);
}

TEST_P(NumberOfSegmentsInAStringTest, Example2) {
  NumberOfSegmentsInAStringSolution solution;
  solution.setStrategy(GetParam());
  EXPECT_EQ(solution.countSegments("Hello"), 1);
}

INSTANTIATE_TEST_SUITE_P(NumberOfSegmentsInAStringTestCases,
                         NumberOfSegmentsInAStringTest,
                         testing::ValuesIn(NumberOfSegmentsInAStringSolution().getStrategyNames()));

}  // namespace problem_434
}  // namespace leetcode
