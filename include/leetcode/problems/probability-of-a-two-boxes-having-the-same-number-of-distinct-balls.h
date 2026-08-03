#ifndef LEETCODE_PROBLEM_1467_H_
#define LEETCODE_PROBLEM_1467_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1467 {

using Func = std::function<double(std::vector<int>&)>;

class ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution
    : public SolutionBase<Func> {
 public:
  double getProbability(std::vector<int>& balls);

  ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution();
};

}  // namespace problem_1467
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1467_H_
