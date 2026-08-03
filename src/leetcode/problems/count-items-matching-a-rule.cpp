#include "leetcode/problems/count-items-matching-a-rule.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1773 {

namespace {

int countMatchesImpl(std::vector<std::vector<std::string>>& items,
                     std::string ruleKey, std::string ruleValue) {
  int index = 0;
  if (ruleKey == "color") {
    index = 1;
  } else if (ruleKey == "name") {
    index = 2;
  }
  int count = 0;
  for (const auto& item : items) {
    if (item[index] == ruleValue) {
      ++count;
    }
  }
  return count;
}

}  // namespace

CountItemsMatchingARuleSolution::CountItemsMatchingARuleSolution() {
  setMetaInfo({.id = 1773,
               .title = "Count Items Matching a Rule",
               .url = "https://leetcode.com/problems/count-items-matching-a-rule/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String"}},
      countMatchesImpl);
}

int CountItemsMatchingARuleSolution::countMatches(
    std::vector<std::vector<std::string>>& items, std::string ruleKey,
    std::string ruleValue) {
  return getSolution()(items, ruleKey, ruleValue);
}

}  // namespace problem_1773
}  // namespace leetcode
