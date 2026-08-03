#ifndef LEETCODE_PROBLEM_3110_H_
#define LEETCODE_PROBLEM_3110_H_

#include "leetcode/core.h"

namespace leetcode::problem_3110 {

using Func = std::function<int(std::string)>;

class ScoreOfAStringSolution : public SolutionBase<Func> {
 public:
  ScoreOfAStringSolution();

  int scoreOfString(std::string s);
};

}  // namespace leetcode::problem_3110

#endif  // LEETCODE_PROBLEM_3110_H_
