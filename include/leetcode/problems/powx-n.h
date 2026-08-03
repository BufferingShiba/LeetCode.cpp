#ifndef LEETCODE_PROBLEMS_POWX_N_H__
#define LEETCODE_PROBLEMS_POWX_N_H__

#include <cmath>
#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_50 {

using Func = std::function<double(double, int)>;

class PowxNSolution : public SolutionBase<Func> {
 public:
  PowxNSolution();

  double myPow(double x, int n);
};

}  // namespace problem_50
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POWX_N_H__
