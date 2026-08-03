#ifndef LEETCODE_PROBLEMS_REACH_A_NUMBER_H_
#define LEETCODE_PROBLEMS_REACH_A_NUMBER_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_754 {

using Func = std::function<int(int)>;

class ReachANumberSolution : public SolutionBase<Func> {
 public:
  ReachANumberSolution();

  int reachNumber(int target);
};

}  // namespace problem_754
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REACH_A_NUMBER_H_
