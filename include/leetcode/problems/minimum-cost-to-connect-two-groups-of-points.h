#ifndef LEETCODE_PROBLEMS_1595_H__
#define LEETCODE_PROBLEMS_1595_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1595 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumCostToConnectTwoGroupsOfPointsSolution : public SolutionBase<Func> {
 public:
  MinimumCostToConnectTwoGroupsOfPointsSolution();

  int connectTwoGroups(std::vector<std::vector<int>>& cost) {
    return getSolution()(cost);
  }
};

}  // namespace problem_1595
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_1595_H__
