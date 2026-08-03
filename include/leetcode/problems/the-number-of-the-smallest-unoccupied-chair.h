#ifndef LEETCODE_THE_NUMBER_OF_THE_SMALLEST_UNOCCUPIED_CHAIR_H__
#define LEETCODE_THE_NUMBER_OF_THE_SMALLEST_UNOCCUPIED_CHAIR_H__

#include "leetcode/core.h"

namespace leetcode::problem_1942 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class TheNumberOfTheSmallestUnoccupiedChairSolution : public SolutionBase<Func> {
 public:
  TheNumberOfTheSmallestUnoccupiedChairSolution();

  int smallestChair(std::vector<std::vector<int>>& times, int targetFriend);
};

}  // namespace leetcode::problem_1942

#endif  // LEETCODE_THE_NUMBER_OF_THE_SMALLEST_UNOCCUPIED_CHAIR_H__
