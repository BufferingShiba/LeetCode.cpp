#ifndef LEETCODE_PROBLEMS_REFORMAT_DATE_H__
#define LEETCODE_PROBLEMS_REFORMAT_DATE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1507 {

using Func = std::function<std::string(std::string)>;

class ReformatDateSolution : public SolutionBase<Func> {
 public:
  ReformatDateSolution();

  std::string reformatDate(std::string date);
};

}  // namespace leetcode::problem_1507

#endif  // LEETCODE_PROBLEMS_REFORMAT_DATE_H__
