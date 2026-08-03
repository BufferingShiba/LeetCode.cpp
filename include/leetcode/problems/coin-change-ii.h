#ifndef LEETCODE_PROBLEMS_COIN_CHANGE_II_H_
#define LEETCODE_PROBLEMS_COIN_CHANGE_II_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_518 {

using Func = std::function<int(int, std::vector<int>&)>;

class CoinChangeIiSolution : public SolutionBase<Func> {
 public:
  CoinChangeIiSolution();

  int change(int amount, std::vector<int>& coins);
};

}  // namespace problem_518
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COIN_CHANGE_II_H_
