#ifndef LEETCODE_PROBLEMS_MINIMUM_TIME_TO_REVERT_WORD_TO_INITIAL_STATE_I_H__
#define LEETCODE_PROBLEMS_MINIMUM_TIME_TO_REVERT_WORD_TO_INITIAL_STATE_I_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3029 {

using Func = std::function<int(std::string, int)>;

class MinimumTimeToRevertWordToInitialStateISolution
    : public SolutionBase<Func> {
 public:
  MinimumTimeToRevertWordToInitialStateISolution();

  int minimumTimeToInitialState(std::string word, int k);
};

}  // namespace leetcode::problem_3029

#endif  // LEETCODE_PROBLEMS_MINIMUM_TIME_TO_REVERT_WORD_TO_INITIAL_STATE_I_H__
