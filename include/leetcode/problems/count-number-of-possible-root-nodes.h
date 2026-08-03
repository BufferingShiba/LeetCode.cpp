#ifndef LEETCODE_PROBLEM_2581_COUNT_NUMBER_OF_POSSIBLE_ROOT_NODES_H_
#define LEETCODE_PROBLEM_2581_COUNT_NUMBER_OF_POSSIBLE_ROOT_NODES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2581 {

using Func = std::function<int(std::vector<std::vector<int>>&, std::vector<std::vector<int>>&, int)>;

class CountNumberOfPossibleRootNodesSolution : public SolutionBase<Func> {
 public:
  CountNumberOfPossibleRootNodesSolution();

  int rootCount(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& guesses, int k);
};

}  // namespace problem_2581
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2581_COUNT_NUMBER_OF_POSSIBLE_ROOT_NODES_H_
