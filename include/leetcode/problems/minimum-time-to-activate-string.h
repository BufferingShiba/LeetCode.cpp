#ifndef LEETCODE_PROBLEMS_MINIMUM_TIME_TO_ACTIVATE_STRING_H_
#define LEETCODE_PROBLEMS_MINIMUM_TIME_TO_ACTIVATE_STRING_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3639 {

using Func = std::function<int(std::string, std::vector<int>&, int)>;

class MinimumTimeToActivateStringSolution : public SolutionBase<Func> {
 public:
  MinimumTimeToActivateStringSolution();

  int minTime(std::string s, std::vector<int>& order, int k);
};

}  // namespace leetcode::problem_3639

#endif  // LEETCODE_PROBLEMS_MINIMUM_TIME_TO_ACTIVATE_STRING_H_
