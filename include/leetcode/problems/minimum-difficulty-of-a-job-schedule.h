#ifndef LEETCODE_PROBLEMS_MINIMUM_DIFFICULTY_OF_A_JOB_SCHEDULE_H_
#define LEETCODE_PROBLEMS_MINIMUM_DIFFICULTY_OF_A_JOB_SCHEDULE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1335 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumDifficultyOfAJobScheduleSolution : public SolutionBase<Func> {
 public:
  MinimumDifficultyOfAJobScheduleSolution();

  int minDifficulty(std::vector<int>& jobDifficulty, int d);
};

}  // namespace problem_1335
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DIFFICULTY_OF_A_JOB_SCHEDULE_H_
