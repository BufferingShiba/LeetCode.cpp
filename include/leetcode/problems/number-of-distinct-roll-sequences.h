#ifndef LEETCODE_PROBLEMS_NUMBER_OF_DISTINCT_ROLL_SEQUENCES_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_DISTINCT_ROLL_SEQUENCES_H_

#include "leetcode/core.h"

namespace leetcode::problem_2318 {

using Func = std::function<int(int)>;

class NumberOfDistinctRollSequencesSolution : public SolutionBase<Func> {
 public:
  NumberOfDistinctRollSequencesSolution();
  int distinctSequences(int n);
};

}  // namespace leetcode::problem_2318

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_DISTINCT_ROLL_SEQUENCES_H_
