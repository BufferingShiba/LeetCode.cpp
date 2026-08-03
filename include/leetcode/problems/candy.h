#ifndef LEETCODE_PROBLEMS_CANDY_H__
#define LEETCODE_PROBLEMS_CANDY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_135 {

using Func = std::function<int(std::vector<int>&)>;

class CandySolution : public SolutionBase<Func> {
 public:
  CandySolution();

  int candy(std::vector<int>& ratings);
};

}  // namespace leetcode::problem_135

#endif  // LEETCODE_PROBLEMS_CANDY_H__
