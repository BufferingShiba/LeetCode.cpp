#include "leetcode/problems/minimum-non-zero-product-of-the-array-elements.h"
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1969 {
namespace {

class MinimumNonZeroProductOfTheArrayElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNonZeroProductOfTheArrayElementsSolution solution;
};

TEST_P(MinimumNonZeroProductOfTheArrayElementsTest, Example1) {
  EXPECT_EQ(solution.minNonZeroProduct(1), 1);
}

TEST_P(MinimumNonZeroProductOfTheArrayElementsTest, Example2) {
  EXPECT_EQ(solution.minNonZeroProduct(2), 6);
}

TEST_P(MinimumNonZeroProductOfTheArrayElementsTest, Example3) {
  EXPECT_EQ(solution.minNonZeroProduct(3), 1512);
}

TEST_P(MinimumNonZeroProductOfTheArrayElementsTest, LargerCase) {
  // p = 4: (2^4-2)^(2^3-1) * (2^4-1) = 14^7 * 15 mod (1e9+7).
  // 14^7 = 105413504; 105413504 * 15 = 1581202560; 1581202560 % (1e9+7) = 581202553.
  EXPECT_EQ(solution.minNonZeroProduct(4), 581202553);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNonZeroProductOfTheArrayElementsTestSuite,
    MinimumNonZeroProductOfTheArrayElementsTest,
    ::testing::ValuesIn(MinimumNonZeroProductOfTheArrayElementsSolution()
                            .getStrategyNames()));

}  // namespace
}  // namespace problem_1969
}  // namespace leetcode
