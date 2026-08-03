#ifndef LEETCODE_PROBLEMS_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H_
#define LEETCODE_PROBLEMS_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_787 {

using Func = std::function<int(int, std::vector<std::vector<int>>&, int, int, int)>;

class CheapestFlightsWithinKStopsSolution : public SolutionBase<Func> {
 public:
  CheapestFlightsWithinKStopsSolution();
  int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src,
                        int dst, int k);
};

}  // namespace leetcode::problem_787

#endif  // LEETCODE_PROBLEMS_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H_
