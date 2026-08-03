#ifndef LEETCODE_MAXIMUM_SCORE_OF_A_NODE_SEQUENCE_H__
#define LEETCODE_MAXIMUM_SCORE_OF_A_NODE_SEQUENCE_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2242 {

using Func = std::function<int(std::vector<int>&, std::vector<std::vector<int>>&)>;

class MaximumScoreOfANodeSequenceSolution : public SolutionBase<Func> {
 public:
  MaximumScoreOfANodeSequenceSolution();

  int maximumScore(std::vector<int>& scores, std::vector<std::vector<int>>& edges);
};

}  // namespace problem_2242
}  // namespace leetcode

#endif  // LEETCODE_MAXIMUM_SCORE_OF_A_NODE_SEQUENCE_H__
