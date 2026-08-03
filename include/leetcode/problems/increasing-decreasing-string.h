#ifndef LEETCODE_PROBLEMS_INCREASING_DECREASING_STRING_H_
#define LEETCODE_PROBLEMS_INCREASING_DECREASING_STRING_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1370 {

using Func = std::function<std::string(std::string)>;

class IncreasingDecreasingStringSolution : public SolutionBase<Func> {
 public:
  std::string sortString(const std::string& s);

  IncreasingDecreasingStringSolution();
};

}  // namespace leetcode::problem_1370

#endif  // LEETCODE_PROBLEMS_INCREASING_DECREASING_STRING_H_
