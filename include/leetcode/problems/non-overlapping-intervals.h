#ifndef LEETCODE_PROBLEMS_NON_OVERLAPPING_INTERVALS_H_
#define LEETCODE_PROBLEMS_NON_OVERLAPPING_INTERVALS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_435 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NonOverlappingIntervalsSolution : public SolutionBase<Func> {
 public:
  NonOverlappingIntervalsSolution();

  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals);
};

}  // namespace problem_435
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NON_OVERLAPPING_INTERVALS_H_
