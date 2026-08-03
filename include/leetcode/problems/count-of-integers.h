#ifndef LEETCODE_PROBLEMS_COUNT_OF_INTEGERS_H__
#define LEETCODE_PROBLEMS_COUNT_OF_INTEGERS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2719 {

using Func = std::function<int(std::string, std::string, int, int)>;

class CountOfIntegersSolution : public SolutionBase<Func> {
 public:
  CountOfIntegersSolution();

  int count(std::string num1, std::string num2, int min_sum, int max_sum);
};

}  // namespace leetcode::problem_2719

#endif  // LEETCODE_PROBLEMS_COUNT_OF_INTEGERS_H__
