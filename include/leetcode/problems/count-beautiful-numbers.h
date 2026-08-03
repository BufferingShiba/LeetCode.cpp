#ifndef LEETCODE_PROBLEMS_COUNT_BEAUTIFUL_NUMBERS_H_
#define LEETCODE_PROBLEMS_COUNT_BEAUTIFUL_NUMBERS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3490 {

using Func = std::function<int(int, int)>;

class CountBeautifulNumbersSolution : public SolutionBase<Func> {
 public:
  int beautifulNumbers(int l, int r);
  CountBeautifulNumbersSolution();
};

}  // namespace leetcode::problem_3490

#endif  // LEETCODE_PROBLEMS_COUNT_BEAUTIFUL_NUMBERS_H_
