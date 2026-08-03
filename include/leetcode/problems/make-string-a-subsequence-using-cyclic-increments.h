#ifndef LEETCODE_PROBLEMS_MAKE_STRING_A_SUBSEQUENCE_USING_CYCLIC_INCREMENTS_H_
#define LEETCODE_PROBLEMS_MAKE_STRING_A_SUBSEQUENCE_USING_CYCLIC_INCREMENTS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2825 {

using Func = std::function<bool(std::string, std::string)>;

class MakeStringASubsequenceUsingCyclicIncrementsSolution : public SolutionBase<Func> {
 public:
  MakeStringASubsequenceUsingCyclicIncrementsSolution();

  bool canMakeSubsequence(std::string str1, std::string str2);
};

}  // namespace problem_2825
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAKE_STRING_A_SUBSEQUENCE_USING_CYCLIC_INCREMENTS_H_
