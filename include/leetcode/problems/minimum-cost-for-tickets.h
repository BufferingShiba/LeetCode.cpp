#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_FOR_TICKETS_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_FOR_TICKETS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_983 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MinimumCostForTicketsSolution : public SolutionBase<Func> {
 public:
  MinimumCostForTicketsSolution();

  int mincostTickets(std::vector<int>& days, std::vector<int>& costs);
};

}  // namespace problem_983
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_FOR_TICKETS_H__
