#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_ARRIVE_AT_DESTINATION_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_ARRIVE_AT_DESTINATION_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_1976 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class NumberOfWaysToArriveAtDestinationSolution : public SolutionBase<Func> {
 public:
  NumberOfWaysToArriveAtDestinationSolution();
  int countPaths(int n, std::vector<std::vector<int>>& roads);
};

}  // namespace leetcode::problem_1976

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_ARRIVE_AT_DESTINATION_H__
