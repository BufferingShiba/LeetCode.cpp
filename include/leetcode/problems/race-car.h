#ifndef LEETCODE_PROBLEMS_RACE_CAR_H_
#define LEETCODE_PROBLEMS_RACE_CAR_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_818 {

using Func = std::function<int(int)>;

class RaceCarSolution : public SolutionBase<Func> {
 public:
  int racecar(int target);
  RaceCarSolution();
};

}  // namespace problem_818
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RACE_CAR_H_
