#ifndef LEETCODE_PROBLEMS_WORD_PATTERN_H__
#define LEETCODE_PROBLEMS_WORD_PATTERN_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_290 {

using Func = std::function<bool(std::string, std::string)>;

class WordPatternSolution : public SolutionBase<Func> {
 public:
  WordPatternSolution();
  bool wordPattern(std::string pattern, std::string s);
};

}  // namespace leetcode::problem_290

#endif  // LEETCODE_PROBLEMS_WORD_PATTERN_H__
