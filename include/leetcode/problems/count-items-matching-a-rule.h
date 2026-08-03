#ifndef LEETCODE_PROBLEMS_COUNT_ITEMS_MATCHING_A_RULE_H__
#define LEETCODE_PROBLEMS_COUNT_ITEMS_MATCHING_A_RULE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1773 {

using Func = std::function<int(std::vector<std::vector<std::string>>&,
                               std::string, std::string)>;

class CountItemsMatchingARuleSolution : public SolutionBase<Func> {
 public:
  CountItemsMatchingARuleSolution();

  int countMatches(std::vector<std::vector<std::string>>& items,
                   std::string ruleKey, std::string ruleValue);
};

}  // namespace problem_1773
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_ITEMS_MATCHING_A_RULE_H__
