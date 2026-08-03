#ifndef LEETCODE_PROBLEMS_VALID_PERFECT_SQUARE_H_
#define LEETCODE_PROBLEMS_VALID_PERFECT_SQUARE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_367 {

using Func = std::function<bool(int)>;

class ValidPerfectSquareSolution : public SolutionBase<Func> {
 public:
  ValidPerfectSquareSolution();
  bool isPerfectSquare(int num);
};

}  // namespace problem_367
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_PERFECT_SQUARE_H_
