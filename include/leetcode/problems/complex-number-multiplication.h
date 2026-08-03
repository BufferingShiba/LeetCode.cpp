#ifndef LEETCODE_PROBLEMS_COMPLEX_NUMBER_MULTIPLICATION_H__
#define LEETCODE_PROBLEMS_COMPLEX_NUMBER_MULTIPLICATION_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_537 {

using Func = std::function<std::string(std::string, std::string)>;

class ComplexNumberMultiplicationSolution : public SolutionBase<Func> {
 public:
  ComplexNumberMultiplicationSolution();

  std::string complexNumberMultiply(const std::string& num1, const std::string& num2);
};

}  // namespace problem_537
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COMPLEX_NUMBER_MULTIPLICATION_H__
