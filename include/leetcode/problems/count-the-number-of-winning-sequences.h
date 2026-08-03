#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_WINNING_SEQUENCES_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_WINNING_SEQUENCES_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3320 {

using Func = std::function<int(std::string)>;

class CountTheNumberOfWinningSequencesSolution
    : public SolutionBase<Func> {
 public:
  CountTheNumberOfWinningSequencesSolution();

  int countWinningSequences(std::string s);
};

}  // namespace leetcode::problem_3320

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_WINNING_SEQUENCES_H__
