#ifndef LEETCODE_PROBLEMS_SUBSEQUENCE_AFTER_ONE_REPLACEMENT_H__
#define LEETCODE_PROBLEMS_SUBSEQUENCE_AFTER_ONE_REPLACEMENT_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3983 {

using Func = std::function<bool(std::string, std::string)>;

class SubsequenceAfterOneReplacementSolution
    : public SolutionBase<Func> {
 public:
  SubsequenceAfterOneReplacementSolution();

  bool canMakeSubsequence(std::string s, std::string t);
};

}  // namespace problem_3983
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUBSEQUENCE_AFTER_ONE_REPLACEMENT_H__
