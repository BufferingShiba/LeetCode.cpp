#ifndef LEETCODE_PROBLEMS_ALTERNATING_DIGIT_SUM_H_
#define LEETCODE_PROBLEMS_ALTERNATING_DIGIT_SUM_H_

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2544 {

using Func = std::function<int(int)>;

class AlternatingDigitSumSolution : public SolutionBase<Func> {
 public:
  AlternatingDigitSumSolution();
  int alternateDigitSum(int n);
};

}  // namespace problem_2544
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ALTERNATING_DIGIT_SUM_H_
