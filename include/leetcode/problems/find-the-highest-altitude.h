#ifndef LEETCODE_PROBLEMS_FIND_THE_HIGHEST_ALTITUDE_H_
#define LEETCODE_PROBLEMS_FIND_THE_HIGHEST_ALTITUDE_H_

#include "leetcode/core.h"

namespace leetcode::problem_1732 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheHighestAltitudeSolution : public SolutionBase<Func> {
 public:
  FindTheHighestAltitudeSolution();

  int largestAltitude(std::vector<int>& gain);
};

}  // namespace leetcode::problem_1732

#endif  // LEETCODE_PROBLEMS_FIND_THE_HIGHEST_ALTITUDE_H_
