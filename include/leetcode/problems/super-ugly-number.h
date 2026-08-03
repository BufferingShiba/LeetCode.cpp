#pragma once

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_313 {

using Func = std::function<int(int, std::vector<int>&)>;

class SuperUglyNumberSolution : public SolutionBase<Func> {
 public:
  SuperUglyNumberSolution();
  int nthSuperUglyNumber(int n, std::vector<int>& primes);
};

}  // namespace leetcode::problem_313