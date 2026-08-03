#ifndef LEETCODE_PROBLEMS_DIGIT_FREQUENCY_SCORE_H__
#define LEETCODE_PROBLEMS_DIGIT_FREQUENCY_SCORE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3945 {

using Func = std::function<int(int)>;

class DigitFrequencyScoreSolution : public SolutionBase<Func> {
 public:
  DigitFrequencyScoreSolution();
  int digitFrequencyScore(int n);
};

}  // namespace leetcode::problem_3945

#endif  // LEETCODE_PROBLEMS_DIGIT_FREQUENCY_SCORE_H__
