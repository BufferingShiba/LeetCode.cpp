#ifndef LEETCODE_PROBLEMS_ONES_AND_ZEROES_H__
#define LEETCODE_PROBLEMS_ONES_AND_ZEROES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_474 {

using Func = std::function<int(std::vector<std::string>&, int, int)>;

class OnesAndZeroesSolution : public SolutionBase<Func> {
 public:
  OnesAndZeroesSolution();
  int findMaxForm(std::vector<std::string>& strs, int m, int n);
};

}  // namespace leetcode::problem_474

#endif  // LEETCODE_PROBLEMS_ONES_AND_ZEROES_H__
