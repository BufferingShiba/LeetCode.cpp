#ifndef LEETCODE_PROBLEMS_FROG_POSITION_AFTER_T_SECONDS_H__
#define LEETCODE_PROBLEMS_FROG_POSITION_AFTER_T_SECONDS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1377 {

class FrogPositionAfterTSecondsSolution
    : public SolutionBase<std::function<double(int, std::vector<std::vector<int>>&, int, int)>> {
 public:
  FrogPositionAfterTSecondsSolution();
  double frogPosition(int n, std::vector<std::vector<int>>& edges, int t, int target);
};

}  // namespace problem_1377
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FROG_POSITION_AFTER_T_SECONDS_H__
