#ifndef LEETCODE_PROBLEMS_LEMONADE_CHANGE_H__
#define LEETCODE_PROBLEMS_LEMONADE_CHANGE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_860 {

using Func = std::function<bool(std::vector<int>&)>;

class LemonadeChangeSolution : public SolutionBase<Func> {
 public:
  LemonadeChangeSolution();

  bool lemonadeChange(std::vector<int>& bills);
};

}  // namespace leetcode::problem_860

#endif  // LEETCODE_PROBLEMS_LEMONADE_CHANGE_H__
