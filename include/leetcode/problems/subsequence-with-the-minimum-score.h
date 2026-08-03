#ifndef LEETCODE_PROBLEMS_SUBSEQUENCE_WITH_THE_MINIMUM_SCORE_H__
#define LEETCODE_PROBLEMS_SUBSEQUENCE_WITH_THE_MINIMUM_SCORE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2565 {

using Func = std::function<int(std::string, std::string)>;

class SubsequenceWithTheMinimumScoreSolution
    : public SolutionBase<Func> {
 public:
  SubsequenceWithTheMinimumScoreSolution();

  int minimumScore(std::string s, std::string t);
};

}  // namespace problem_2565
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUBSEQUENCE_WITH_THE_MINIMUM_SCORE_H__
