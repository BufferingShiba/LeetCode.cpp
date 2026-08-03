#ifndef LEETCODE_PROBLEMS_COUNT_NUMBER_OF_SPECIAL_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_COUNT_NUMBER_OF_SPECIAL_SUBSEQUENCES_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_1955 {

using Func = std::function<int(std::vector<int>&)>;

class CountNumberOfSpecialSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  CountNumberOfSpecialSubsequencesSolution();

  int countSpecialSubsequences(std::vector<int>& nums);
};

}  // namespace problem_1955
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NUMBER_OF_SPECIAL_SUBSEQUENCES_H__
