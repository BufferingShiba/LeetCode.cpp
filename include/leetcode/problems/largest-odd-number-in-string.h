#ifndef LEETCODE_PROBLEMS_LARGEST_ODD_NUMBER_IN_STRING_H__
#define LEETCODE_PROBLEMS_LARGEST_ODD_NUMBER_IN_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1903 {

using Func = std::function<std::string(std::string)>;

class LargestOddNumberInStringSolution
    : public SolutionBase<Func> {
 public:
  LargestOddNumberInStringSolution();

  std::string largestOddNumber(std::string num);
};

}  // namespace problem_1903
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_ODD_NUMBER_IN_STRING_H__
