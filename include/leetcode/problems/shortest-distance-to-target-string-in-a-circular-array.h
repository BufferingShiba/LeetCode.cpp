#ifndef LEETCODE_PROBLEMS_SHORTEST_DISTANCE_TO_TARGET_STRING_IN_A_CIRCULAR_ARRAY_H__
#define LEETCODE_PROBLEMS_SHORTEST_DISTANCE_TO_TARGET_STRING_IN_A_CIRCULAR_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2515 {

using Func = std::function<int(std::vector<std::string>&, std::string, int)>;

class ShortestDistanceToTargetStringInACircularArraySolution
    : public SolutionBase<Func> {
 public:
  ShortestDistanceToTargetStringInACircularArraySolution();

  int closestTarget(std::vector<std::string>& words, std::string target,
                    int startIndex);
};

}  // namespace leetcode::problem_2515

#endif  // LEETCODE_PROBLEMS_SHORTEST_DISTANCE_TO_TARGET_STRING_IN_A_CIRCULAR_ARRAY_H__
