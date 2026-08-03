#ifndef LEETCODE_PROBLEMS_CAPITALIZE_THE_TITLE_H__
#define LEETCODE_PROBLEMS_CAPITALIZE_THE_TITLE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2129 {

using Func = std::function<std::string(std::string)>;

class CapitalizeTheTitleSolution : public SolutionBase<Func> {
 public:
  CapitalizeTheTitleSolution();
  std::string capitalizeTitle(const std::string& title) const;
};

}  // namespace leetcode::problem_2129

#endif  // LEETCODE_PROBLEMS_CAPITALIZE_THE_TITLE_H__
