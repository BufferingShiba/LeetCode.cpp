#ifndef LEETCODE_PROBLEMS_FIND_MINIMUM_TIME_TO_FINISH_ALL_JOBS_H__
#define LEETCODE_PROBLEMS_FIND_MINIMUM_TIME_TO_FINISH_ALL_JOBS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1723 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindMinimumTimeToFinishAllJobsSolution
    : public SolutionBase<Func> {
 public:
  FindMinimumTimeToFinishAllJobsSolution();
  int minimumTimeRequired(std::vector<int>& jobs, int k);
};

}  // namespace problem_1723
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_MINIMUM_TIME_TO_FINISH_ALL_JOBS_H__
