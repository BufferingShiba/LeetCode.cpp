#ifndef LEETCODE_PROBLEM_NUMBER_OF_BOOMERANGS_H
#define LEETCODE_PROBLEM_NUMBER_OF_BOOMERANGS_H

#include "leetcode/core.h"

namespace leetcode::problem_447 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfBoomerangsSolution : public SolutionBase<Func> {
 public:
  NumberOfBoomerangsSolution();

  int numberOfBoomerangs(std::vector<std::vector<int>>& points);
};

}  // namespace leetcode::problem_447

#endif  // LEETCODE_PROBLEM_NUMBER_OF_BOOMERANGS_H
