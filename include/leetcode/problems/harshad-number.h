#ifndef LEETCODE_PROBLEMS_HARSHAD_NUMBER_H__
#define LEETCODE_PROBLEMS_HARSHAD_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3099 {

using Func = std::function<int(int)>;

class HarshadNumberSolution : public SolutionBase<Func> {
 public:
  HarshadNumberSolution();

  int sumOfTheDigitsOfHarshadNumber(int x);
};

}  // namespace problem_3099
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_HARSHAD_NUMBER_H__
