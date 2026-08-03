#include "leetcode/core.h"

namespace leetcode {
namespace problem_2462 {

using Func = std::function<long long(vector<int>&, int, int)>;

class TotalCostToHireKWorkersSolution : public SolutionBase<Func> {
 public:
  //! 2462. Total Cost to Hire K Workers
  //! https://leetcode.com/problems/total-cost-to-hire-k-workers/
  long long totalCost(vector<int>& costs, int k, int candidates);

  TotalCostToHireKWorkersSolution();
};

}  // namespace problem_2462
}  // namespace leetcode
