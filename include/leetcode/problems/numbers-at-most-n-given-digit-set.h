#ifndef LEETCODE_PROBLEM_902_H
#define LEETCODE_PROBLEM_902_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_902 {

using Func = std::function<int(std::vector<std::string>&, int)>;

class NumbersAtMostNGivenDigitSetSolution : public SolutionBase<Func> {
 public:
  int atMostNGivenDigitSet(std::vector<std::string>& digits, int n);

  NumbersAtMostNGivenDigitSetSolution();
};

}  // namespace problem_902
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_902_H
