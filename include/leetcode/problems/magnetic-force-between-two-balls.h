#ifndef LEETCODE_PROBLEMS_MAGNETIC_FORCE_BETWEEN_TWO_BALLS_H_
#define LEETCODE_PROBLEMS_MAGNETIC_FORCE_BETWEEN_TWO_BALLS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1552 {

using Func = std::function<int(std::vector<int>&, int)>;

class MagneticForceBetweenTwoBallsSolution : public SolutionBase<Func> {
 public:
  MagneticForceBetweenTwoBallsSolution();

  int maxDistance(std::vector<int>& position, int m);
};

}  // namespace problem_1552
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAGNETIC_FORCE_BETWEEN_TWO_BALLS_H_
