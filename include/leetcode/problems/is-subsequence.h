#ifndef LEETCODE_PROBLEMS_IS_SUBSEQUENCE_H__
#define LEETCODE_PROBLEMS_IS_SUBSEQUENCE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_392 {

using Func = std::function<bool(std::string, std::string)>;

class IsSubsequenceSolution : public SolutionBase<Func> {
 public:
  IsSubsequenceSolution();

  bool isSubsequence(std::string s, std::string t);
};

}  // namespace problem_392
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_IS_SUBSEQUENCE_H__
