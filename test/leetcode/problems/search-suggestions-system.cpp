#include "leetcode/problems/search-suggestions-system.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1268 {
namespace {

class SearchSuggestionsSystemTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SearchSuggestionsSystemSolution solution_;
};

TEST_P(SearchSuggestionsSystemTest, Example1) {
  std::vector<std::string> products = {
      "mobile", "mouse", "moneypot", "monitor", "mousepad"};
  const std::vector<std::vector<std::string>> expected = {
      {"mobile", "moneypot", "monitor"},
      {"mobile", "moneypot", "monitor"},
      {"mouse", "mousepad"},
      {"mouse", "mousepad"},
      {"mouse", "mousepad"}};
  EXPECT_EQ(solution_.suggestedProducts(products, "mouse"), expected);
}

TEST_P(SearchSuggestionsSystemTest, Example2) {
  std::vector<std::string> products = {"havana"};
  const std::vector<std::vector<std::string>> expected = {
      {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"},
      {"havana"}};
  EXPECT_EQ(solution_.suggestedProducts(products, "havana"), expected);
}

TEST_P(SearchSuggestionsSystemTest, NoMatchesAfterPrefix) {
  std::vector<std::string> products = {"bags", "baggage", "banner", "box"};
  const std::vector<std::vector<std::string>> expected = {
      {"baggage", "bags", "banner"}, {"baggage", "bags", "banner"},
      {}, {}};
  EXPECT_EQ(solution_.suggestedProducts(products, "baza"), expected);
}

TEST_P(SearchSuggestionsSystemTest, KeepsOnlyThreeLexicographicallySmallest) {
  std::vector<std::string> products = {"abc4", "abc2", "abc1", "abc3", "abd"};
  const std::vector<std::vector<std::string>> expected = {
      {"abc1", "abc2", "abc3"}, {"abc1", "abc2", "abc3"},
      {"abc1", "abc2", "abc3"}, {"abc4"}};
  EXPECT_EQ(solution_.suggestedProducts(products, "abc4"), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SearchSuggestionsStrategies, SearchSuggestionsSystemTest,
    ::testing::ValuesIn(SearchSuggestionsSystemSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1268
}  // namespace leetcode
