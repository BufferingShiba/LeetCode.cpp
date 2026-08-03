#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_GOOD_NODES_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_GOOD_NODES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3249 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CountTheNumberOfGoodNodesSolution : public SolutionBase<Func> {
 public:
  CountTheNumberOfGoodNodesSolution();

  int countGoodNodes(std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3249
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_GOOD_NODES_H__
