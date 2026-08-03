#ifndef LEETCODE_PROBLEM_1505_H_
#define LEETCODE_PROBLEM_1505_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1505 {

using Func = std::function<std::string(std::string, int)>;

class MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution
    : public SolutionBase<Func> {
 public:
  MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution();

  std::string minInteger(std::string num, int k);
};

}  // namespace problem_1505
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1505_H_
