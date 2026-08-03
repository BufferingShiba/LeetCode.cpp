#ifndef LEETCODE_PROBLEMS_CALCULATE_SCORE_AFTER_PERFORMING_INSTRUCTIONS_H_
#define LEETCODE_PROBLEMS_CALCULATE_SCORE_AFTER_PERFORMING_INSTRUCTIONS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3522 {

using Func = std::function<long long(std::vector<std::string>&, std::vector<int>&)>;

class CalculateScoreAfterPerformingInstructionsSolution
    : public SolutionBase<Func> {
 public:
  CalculateScoreAfterPerformingInstructionsSolution();

  long long calculateScore(std::vector<std::string>& instructions,
                           std::vector<int>& values) {
    return getSolution()(instructions, values);
  }
};

}  // namespace problem_3522
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CALCULATE_SCORE_AFTER_PERFORMING_INSTRUCTIONS_H_
