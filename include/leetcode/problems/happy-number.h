#ifndef LEETCODE_PROBLEMS_HAPPY_NUMBER_H__
#define LEETCODE_PROBLEMS_HAPPY_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_202 {

using Func = std::function<bool(int)>;

class HappyNumberSolution : public SolutionBase<Func> {
 public:
  HappyNumberSolution();

  bool isHappy(int n);
};

}  // namespace problem_202
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_HAPPY_NUMBER_H__
