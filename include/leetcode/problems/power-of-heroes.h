#ifndef LEETCODE_PROBLEMS_POWER_OF_HEROES_H__
#define LEETCODE_PROBLEMS_POWER_OF_HEROES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2681 {

using Func = std::function<int(std::vector<int>&)>;

class PowerOfHeroesSolution : public SolutionBase<Func> {
 public:
  PowerOfHeroesSolution();
};

}  // namespace problem_2681
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POWER_OF_HEROES_H__
