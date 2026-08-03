#ifndef LEETCODE_PROBLEMS_CAR_FLEET_H_
#define LEETCODE_PROBLEMS_CAR_FLEET_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_853 {

using Func = std::function<int(int, std::vector<int>&, std::vector<int>&)>;

class CarFleetSolution : public SolutionBase<Func> {
 public:
  CarFleetSolution();

  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed);
};

}  // namespace problem_853
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CAR_FLEET_H_
