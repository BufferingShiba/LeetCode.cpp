#ifndef LEETCODE_PROBLEMS_MAXIMUM_CONTAINERS_ON_A_SHIP_H__
#define LEETCODE_PROBLEMS_MAXIMUM_CONTAINERS_ON_A_SHIP_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3492 {

using Func = std::function<int(int, int, int)>;

class MaximumContainersOnAShipSolution : public SolutionBase<Func> {
 public:
  MaximumContainersOnAShipSolution();

  int maxContainers(int n, int w, int maxWeight);
};

}  // namespace problem_3492
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_CONTAINERS_ON_A_SHIP_H__
