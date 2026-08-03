#ifndef LEETCODE_PROBLEMS_ARRANGING_COINS_H__
#define LEETCODE_PROBLEMS_ARRANGING_COINS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_441 {

using Func = std::function<int(int)>;

class ArrangingCoinsSolution : public SolutionBase<Func> {
 public:
  ArrangingCoinsSolution();

  int arrangeCoins(int n);
};

}  // namespace leetcode::problem_441

#endif  // LEETCODE_PROBLEMS_ARRANGING_COINS_H__
