#ifndef LEETCODE_PROBLEMS_NUMBER_OF_CLOSED_ISLANDS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_CLOSED_ISLANDS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1254 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfClosedIslandsSolution : public SolutionBase<Func> {
 public:
  NumberOfClosedIslandsSolution();

  int closedIsland(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_1254
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_CLOSED_ISLANDS_H__
