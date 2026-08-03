#ifndef LEETCODE_PROBLEMS_TRANSFORM_BINARY_STRING_USING_SUBSEQUENCE_SORT_H_
#define LEETCODE_PROBLEMS_TRANSFORM_BINARY_STRING_USING_SUBSEQUENCE_SORT_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3998 {

using Func = std::function<std::vector<bool>(std::string, std::vector<std::string>&)>;

class TransformBinaryStringUsingSubsequenceSortSolution : public SolutionBase<Func> {
 public:
  TransformBinaryStringUsingSubsequenceSortSolution();

  std::vector<bool> transformStr(std::string s, std::vector<std::string>& strs);
};

}  // namespace problem_3998
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TRANSFORM_BINARY_STRING_USING_SUBSEQUENCE_SORT_H_
