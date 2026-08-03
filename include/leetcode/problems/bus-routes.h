#ifndef LEETCODE_PROBLEMS_BUS_ROUTES_H_
#define LEETCODE_PROBLEMS_BUS_ROUTES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_815 {

using Func = std::function<int(std::vector<std::vector<int>>&, int, int)>;

class BusRoutesSolution : public SolutionBase<Func> {
 public:
  BusRoutesSolution();

  int numBusesToDestination(std::vector<std::vector<int>>& routes, int source,
                            int target);
};

}  // namespace problem_815
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BUS_ROUTES_H_
