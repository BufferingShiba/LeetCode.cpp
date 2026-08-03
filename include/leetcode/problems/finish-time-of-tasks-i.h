#include "leetcode/core.h"

namespace leetcode {
namespace problem_3965 {

using Func = std::function<long(int, vector<vector<int>>&, vector<int>&)>;

class FinishTimeOfTasksISolution : public SolutionBase<Func> {
 public:
  //! 3965. Finish Time of Tasks I
  //! https://leetcode.com/problems/finish-time-of-tasks-i/
  long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime);

  FinishTimeOfTasksISolution();
};

}  // namespace problem_3965
}  // namespace leetcode
