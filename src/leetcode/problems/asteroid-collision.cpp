#include "leetcode/problems/asteroid-collision.h"

namespace leetcode {
namespace problem_735 {

namespace {

std::vector<int> asteroidCollisionImpl(std::vector<int>& asteroids) {
  std::vector<int> result;
  for (int ast : asteroids) {
    if (ast > 0) {
      result.push_back(ast);
      continue;
    }
    // ast < 0，与栈顶的正值碰撞
    bool exploded = false;
    while (!result.empty() && result.back() > 0) {
      if (result.back() + ast < 0) {
        // 栈顶更小，被消灭
        result.pop_back();
      } else if (result.back() + ast == 0) {
        // 相等，同归于尽
        result.pop_back();
        exploded = true;
        break;
      } else {
        // 栈顶更大，当前被消灭
        exploded = true;
        break;
      }
    }
    if (!exploded) {
      result.push_back(ast);
    }
  }
  return result;
}

}  // namespace

AsteroidCollisionSolution::AsteroidCollisionSolution() {
  setMetaInfo({.id = 735,
               .title = "Asteroid Collision",
               .url =
                   "https://leetcode.com/problems/asteroid-collision/"});
  registerStrategy(
      {"Stack Simulation",
       "Accepted",
       "O(n)",
       "O(n)",
       {"Array", "Stack", "Simulation"}},
      asteroidCollisionImpl);
}

std::vector<int> AsteroidCollisionSolution::asteroidCollision(
    std::vector<int>& asteroids) {
  return getSolution()(asteroids);
}

}  // namespace problem_735
}  // namespace leetcode
