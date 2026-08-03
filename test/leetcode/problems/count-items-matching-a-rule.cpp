#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-items-matching-a-rule.h"

namespace leetcode {
namespace problem_1773 {

class CountItemsMatchingARuleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountItemsMatchingARuleSolution solution;
};

TEST_P(CountItemsMatchingARuleTest, Example1) {
  std::vector<std::vector<std::string>> items = {
      {"phone", "blue", "pixel"},
      {"computer", "silver", "lenovo"},
      {"phone", "gold", "iphone"}};
  EXPECT_EQ(1, solution.countMatches(items, "color", "silver"));
}

TEST_P(CountItemsMatchingARuleTest, Example2) {
  std::vector<std::vector<std::string>> items = {
      {"phone", "blue", "pixel"},
      {"computer", "silver", "phone"},
      {"phone", "gold", "iphone"}};
  EXPECT_EQ(2, solution.countMatches(items, "type", "phone"));
}

TEST_P(CountItemsMatchingARuleTest, SelfAuthoredNameRule) {
  std::vector<std::vector<std::string>> items = {
      {"phone", "blue", "pixel"},
      {"computer", "silver", "phone"}};
  EXPECT_EQ(1, solution.countMatches(items, "name", "pixel"));
}

TEST_P(CountItemsMatchingARuleTest, SelfAuthoredSingleNoMatch) {
  std::vector<std::vector<std::string>> items = {{"phone", "blue", "pixel"}};
  EXPECT_EQ(0, solution.countMatches(items, "color", "gold"));
}

INSTANTIATE_TEST_SUITE_P(
    CountItemsMatchingARuleTests, CountItemsMatchingARuleTest,
    ::testing::ValuesIn(CountItemsMatchingARuleSolution().getStrategyNames()));

}  // namespace problem_1773
}  // namespace leetcode
