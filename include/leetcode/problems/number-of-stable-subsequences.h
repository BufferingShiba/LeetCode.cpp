#ifndef LEETCODE_PROBLEMS_NUMBER_OF_STABLE_SUBSEQUENCES_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_STABLE_SUBSEQUENCES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3686 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfStableSubsequencesSolution
    : public SolutionBase<Func> {
 public:
  NumberOfStableSubsequencesSolution();

  // Problem entry point.
  int countStableSubsequences(std::vector<int>& nums);
};

}  // namespace problem_3686
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_STABLE_SUBSEQUENCES_H__
