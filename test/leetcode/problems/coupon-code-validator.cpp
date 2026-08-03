#include <gtest/gtest.h>

#include "leetcode/problems/coupon-code-validator.h"

namespace leetcode::problem_3606 {

class CouponCodeValidatorTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CouponCodeValidatorSolution solution;
};

TEST_P(CouponCodeValidatorTest, Example1) {
  std::vector<std::string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
  std::vector<std::string> businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
  std::vector<bool> isActive = {true, true, true, true};
  auto result = solution.validateCoupons(code, businessLine, isActive);
  std::vector<std::string> expected = {"PHARMA5", "SAVE20"};
  EXPECT_EQ(result, expected);
}

TEST_P(CouponCodeValidatorTest, Example2) {
  std::vector<std::string> code = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
  std::vector<std::string> businessLine = {"grocery", "electronics", "invalid"};
  std::vector<bool> isActive = {false, true, true};
  auto result = solution.validateCoupons(code, businessLine, isActive);
  std::vector<std::string> expected = {"ELECTRONICS_50"};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CouponCodeValidatorTest,
    testing::ValuesIn(CouponCodeValidatorSolution().getStrategyNames()));

}  // namespace leetcode::problem_3606
