#ifndef LEETCODE_PROBLEMS_CLOSEST_ROOM_H__
#define LEETCODE_PROBLEMS_CLOSEST_ROOM_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1847 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&,
                                            std::vector<std::vector<int>>&)>;

class ClosestRoomSolution : public SolutionBase<Func> {
 public:
  ClosestRoomSolution();

  std::vector<int> closestRoom(std::vector<std::vector<int>>& rooms,
                               std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_1847

#endif  // LEETCODE_PROBLEMS_CLOSEST_ROOM_H__
