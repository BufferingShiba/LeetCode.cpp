#include "leetcode/core.h"

namespace leetcode {
namespace problem_1701 {

using Func = std::function<double(vector<vector<int>>&)>;

class AverageWaitingTimeSolution : public SolutionBase<Func> {
 public:
  //! 1701. Average Waiting Time
  //! https://leetcode.com/problems/average-waiting-time/
  double averageWaitingTime(vector<vector<int>>& customers);

  AverageWaitingTimeSolution();
};

}  // namespace problem_1701
}  // namespace leetcode
