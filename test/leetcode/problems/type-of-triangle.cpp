#include <gtest/gtest.h>
#include "leetcode/problems/type-of-triangle.h"

using namespace leetcode::problem_3024;

class TypeOfTriangleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  TypeOfTriangleSolution solution;
};

TEST_P(TypeOfTriangleTest, Examples) {
  struct TestCase {
    std::vector<int> nums;
    std::string expected;
  };

  std::vector<TestCase> cases = {
      {{3, 3, 3}, "equilateral"},
      {{3, 4, 5}, "scalene"},
  };

  for (const auto& tc : cases) {
    auto nums = tc.nums;
    EXPECT_EQ(solution.triangleType(nums), tc.expected);
  }
}

TEST_P(TypeOfTriangleTest, SelfAuthored) {
  struct TestCase {
    std::vector<int> nums;
    std::string expected;
  };

  std::vector<TestCase> cases = {
      {{2, 2, 3}, "isosceles"},
      {{5, 5, 8}, "isosceles"},
      {{1, 2, 3}, "none"},
  };

  for (const auto& tc : cases) {
    auto nums = tc.nums;
    EXPECT_EQ(solution.triangleType(nums), tc.expected);
  }
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, TypeOfTriangleTest,
                         ::testing::ValuesIn(
                             TypeOfTriangleSolution().getStrategyNames()));
