#ifndef LEETCODE_PROBLEMS_REMOVE_K_DIGITS_H_
#define LEETCODE_PROBLEMS_REMOVE_K_DIGITS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_402 {

using Func = std::function<std::string(std::string, int)>;

class RemoveKDigitsSolution : public SolutionBase<Func> {
 public:
  RemoveKDigitsSolution();
  std::string removeKdigits(std::string num, int k);
};

}  // namespace problem_402
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_K_DIGITS_H_
