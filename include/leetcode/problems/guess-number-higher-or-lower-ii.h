#ifndef LEETCODE_PROBLEMS_GUESS_NUMBER_HIGHER_OR_LOWER_II_H_
#define LEETCODE_PROBLEMS_GUESS_NUMBER_HIGHER_OR_LOWER_II_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_375 {

using Func = std::function<int(int n)>;

class GuessNumberHigherOrLowerIiSolution
    : public SolutionBase<Func> {
 public:
  GuessNumberHigherOrLowerIiSolution();

  int getMoneyAmount(int n);
};

}  // namespace problem_375
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GUESS_NUMBER_HIGHER_OR_LOWER_II_H_
