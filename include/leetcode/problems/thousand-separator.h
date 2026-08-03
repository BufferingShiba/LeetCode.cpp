#ifndef LEETCODE_PROBLEMS_THOUSAND_SEPARATOR_H__
#define LEETCODE_PROBLEMS_THOUSAND_SEPARATOR_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1556 {

using Func = std::function<std::string(int)>;

class ThousandSeparatorSolution : public SolutionBase<Func> {
 public:
  ThousandSeparatorSolution();

  std::string thousandSeparator(int n);
};

}  // namespace leetcode::problem_1556

#endif  // LEETCODE_PROBLEMS_THOUSAND_SEPARATOR_H__
