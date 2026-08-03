#ifndef LEETCODE_PROBLEMS_COUNT_NODES_WITH_THE_HIGHEST_SCORE_H_
#define LEETCODE_PROBLEMS_COUNT_NODES_WITH_THE_HIGHEST_SCORE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2049 {

using Func = std::function<int(std::vector<int>&)>;

class CountNodesWithTheHighestScoreSolution : public SolutionBase<Func> {
 public:
  CountNodesWithTheHighestScoreSolution();
  int countHighestScoreNodes(std::vector<int>& parents);
};

}  // namespace problem_2049
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NODES_WITH_THE_HIGHEST_SCORE_H_
