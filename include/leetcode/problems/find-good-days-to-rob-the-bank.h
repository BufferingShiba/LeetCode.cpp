#ifndef LEETCODE_PROBLEMS_FIND_GOOD_DAYS_TO_ROB_THE_BANK_H_
#define LEETCODE_PROBLEMS_FIND_GOOD_DAYS_TO_ROB_THE_BANK_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2100 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class FindGoodDaysToRobTheBankSolution : public SolutionBase<Func> {
 public:
  FindGoodDaysToRobTheBankSolution();

  std::vector<int> goodDaysToRobBank(std::vector<int>& security, int time);
};

}  // namespace problem_2100
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_GOOD_DAYS_TO_ROB_THE_BANK_H_
