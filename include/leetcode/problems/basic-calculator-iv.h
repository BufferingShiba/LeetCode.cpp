#ifndef LEETCODE_PROBLEMS_BASIC_CALCULATOR_IV_H__
#define LEETCODE_PROBLEMS_BASIC_CALCULATOR_IV_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_770 {

using Func = std::function<std::vector<std::string>(
    std::string, std::vector<std::string>&, std::vector<int>&)>;

class BasicCalculatorIvSolution : public SolutionBase<Func> {
 public:
  BasicCalculatorIvSolution();

  std::vector<std::string> basicCalculatorIV(
      std::string expression, std::vector<std::string>& evalvars,
      std::vector<int>& evalints);
};

}  // namespace problem_770
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BASIC_CALCULATOR_IV_H__
