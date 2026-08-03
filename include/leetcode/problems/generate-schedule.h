#ifndef LEETCODE_PROBLEMS_GENERATE_SCHEDULE_H__
#define LEETCODE_PROBLEMS_GENERATE_SCHEDULE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3680 {

using Func = std::function<std::vector<std::vector<int>>(int)>;

class GenerateScheduleSolution : public SolutionBase<Func> {
 public:
  GenerateScheduleSolution();

  std::vector<std::vector<int>> generateSchedule(int n);
};

}  // namespace problem_3680
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GENERATE_SCHEDULE_H__
