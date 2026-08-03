#ifndef LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_CONVERT_STRING_H__
#define LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_CONVERT_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2027 {

using Func = std::function<int(std::string)>;

class MinimumMovesToConvertStringSolution
    : public SolutionBase<Func> {
 public:
  MinimumMovesToConvertStringSolution();
  int minimumMoves(std::string s);
};

}  // namespace leetcode::problem_2027

#endif  // LEETCODE_PROBLEMS_MINIMUM_MOVES_TO_CONVERT_STRING_H__
