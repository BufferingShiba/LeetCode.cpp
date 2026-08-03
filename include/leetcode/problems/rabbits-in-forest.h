#ifndef LEETCODE_PROBLEMS_RABBITS_IN_FOREST_H__
#define LEETCODE_PROBLEMS_RABBITS_IN_FOREST_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_781 {

using Func = std::function<int(std::vector<int>&)>;

class RabbitsInForestSolution : public SolutionBase<Func> {
 public:
  RabbitsInForestSolution();
  int numRabbits(std::vector<int>& answers);
};

}  // namespace problem_781
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RABBITS_IN_FOREST_H__
