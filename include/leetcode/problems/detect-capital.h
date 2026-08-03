#ifndef LEETCODE_PROBLEM_520_H
#define LEETCODE_PROBLEM_520_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_520 {

using Func = std::function<bool(std::string)>;

class DetectCapitalSolution : public SolutionBase<Func> {
 public:
  DetectCapitalSolution();

  bool detectCapitalUse(std::string word);
};

}  // namespace problem_520
}  // namespace leetcode

#endif
