#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_BALLOONS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_BALLOONS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_1189 {

using Func = std::function<int(std::string)>;

class MaximumNumberOfBalloonsSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfBalloonsSolution();

  int maxNumberOfBalloons(std::string text);
};

}  // namespace leetcode::problem_1189

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_BALLOONS_H__
