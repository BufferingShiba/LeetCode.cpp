#include <gtest/gtest.h>

#include "leetcode/problems/license-key-formatting.h"

namespace leetcode::problem_482 {

class LicenseKeyFormattingTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  LicenseKeyFormattingSolution solution_;
};

TEST_P(LicenseKeyFormattingTest, OfficialExamples) {
  EXPECT_EQ(solution_.licenseKeyFormatting("5F3Z-2e-9-w", 4), "5F3Z-2E9W");
  EXPECT_EQ(solution_.licenseKeyFormatting("2-5g-3-J", 2), "2-5G-3J");
}

TEST_P(LicenseKeyFormattingTest, SelfAuthored) {
  // All dashes
  EXPECT_EQ(solution_.licenseKeyFormatting("---", 3), "");
  // Single char
  EXPECT_EQ(solution_.licenseKeyFormatting("a", 1), "A");
  // No dashes, exact multiple
  EXPECT_EQ(solution_.licenseKeyFormatting("abcd", 2), "AB-CD");
}

INSTANTIATE_TEST_SUITE_P(Strategies, LicenseKeyFormattingTest,
                         ::testing::ValuesIn(LicenseKeyFormattingSolution().getStrategyNames()));

}  // namespace leetcode::problem_482
