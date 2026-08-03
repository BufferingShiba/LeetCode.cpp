#ifndef LEETCODE_PROBLEMS_SCORE_VALIDATOR_H__
#define LEETCODE_PROBLEMS_SCORE_VALIDATOR_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3921 {

using Func = std::function<std::vector<int>(std::vector<std::string>&)>;

class ScoreValidatorSolution : public SolutionBase<Func> {
 public:
  ScoreValidatorSolution();

  std::vector<int> scoreValidator(std::vector<std::string>& events);
};

}  // namespace problem_3921
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SCORE_VALIDATOR_H__
