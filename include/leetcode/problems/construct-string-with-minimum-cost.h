#ifndef LEETCODE_PROBLEMS_CONSTRUCT_STRING_WITH_MINIMUM_COST_H__
#define LEETCODE_PROBLEMS_CONSTRUCT_STRING_WITH_MINIMUM_COST_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3213 {

using Func = std::function<int(std::string, std::vector<std::string>&, std::vector<int>&)>;

class ConstructStringWithMinimumCostSolution : public SolutionBase<Func> {
 public:
  ConstructStringWithMinimumCostSolution();

  int minimumCost(std::string target, std::vector<std::string>& words,
                  std::vector<int>& costs) {
    return getSolution()(target, words, costs);
  }
};

}  // namespace problem_3213
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_STRING_WITH_MINIMUM_COST_H__
