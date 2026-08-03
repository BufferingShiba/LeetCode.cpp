#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/categorize-box-according-to-criteria.h"

namespace leetcode {
namespace problem_2525 {

class CategorizeBoxAccordingToCriteriaTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CategorizeBoxAccordingToCriteriaSolution solution_;
};

TEST_P(CategorizeBoxAccordingToCriteriaTest, Example1) {
  EXPECT_EQ("Heavy", solution_.categorizeBox(1000, 35, 700, 300));
}

TEST_P(CategorizeBoxAccordingToCriteriaTest, Example2) {
  EXPECT_EQ("Neither", solution_.categorizeBox(200, 50, 800, 50));
}

TEST_P(CategorizeBoxAccordingToCriteriaTest, SelfAuthoredBulkyOnly) {
  EXPECT_EQ("Bulky", solution_.categorizeBox(10000, 1, 1, 1));
}

TEST_P(CategorizeBoxAccordingToCriteriaTest, SelfAuthoredBoth) {
  EXPECT_EQ("Both", solution_.categorizeBox(100000, 100000, 100000, 1000));
}

INSTANTIATE_TEST_SUITE_P(
    CategorizeBoxAccordingToCriteriaTestSuites,
    CategorizeBoxAccordingToCriteriaTest,
    ::testing::ValuesIn(CategorizeBoxAccordingToCriteriaSolution().getStrategyNames()));

}  // namespace problem_2525
}  // namespace leetcode
