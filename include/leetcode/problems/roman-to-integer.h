#ifndef LEETCODE_PROBLEMS_ROMAN_TO_INTEGER_H__
#define LEETCODE_PROBLEMS_ROMAN_TO_INTEGER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_13 {

using Func = std::function<int(std::string)>;

class RomanToIntegerSolution : public SolutionBase<Func> {
 public:
  RomanToIntegerSolution();

  int romanToInt(std::string s);
};

}  // namespace problem_13
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ROMAN_TO_INTEGER_H__
