#ifndef LEETCODE_PROBLEMS_ASTEROID_COLLISION_H_
#define LEETCODE_PROBLEMS_ASTEROID_COLLISION_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_735 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class AsteroidCollisionSolution : public SolutionBase<Func> {
 public:
  AsteroidCollisionSolution();
  std::vector<int> asteroidCollision(std::vector<int>& asteroids);
};

}  // namespace problem_735
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ASTEROID_COLLISION_H_
