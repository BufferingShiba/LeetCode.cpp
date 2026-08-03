#ifndef LEETCODE_PROBLEMS_MOVEMENT_OF_ROBOTS_H__
#define LEETCODE_PROBLEMS_MOVEMENT_OF_ROBOTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2731 {

using Func = std::function<int(std::vector<int>&, std::string&, int)>;

class MovementOfRobotsSolution : public SolutionBase<Func> {
 public:
  MovementOfRobotsSolution();

  int sumDistance(std::vector<int>& nums, std::string& s, int d);
};

}  // namespace problem_2731
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOVEMENT_OF_ROBOTS_H__
