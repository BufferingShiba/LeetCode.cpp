#ifndef LEETCODE_PROBLEMS_TIME_TAKEN_TO_MARK_ALL_NODES_H__
#define LEETCODE_PROBLEMS_TIME_TAKEN_TO_MARK_ALL_NODES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3241 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class TimeTakenToMarkAllNodesSolution : public SolutionBase<Func> {
 public:
  TimeTakenToMarkAllNodesSolution();

  std::vector<int> timeTaken(std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3241
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TIME_TAKEN_TO_MARK_ALL_NODES_H__
