#ifndef LEETCODE_PROBLEMS_FIND_THE_GRID_OF_REGION_AVERAGE_H_
#define LEETCODE_PROBLEMS_FIND_THE_GRID_OF_REGION_AVERAGE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3030 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&, int)>;

class FindTheGridOfRegionAverageSolution
    : public SolutionBase<Func> {
 public:
  FindTheGridOfRegionAverageSolution();

  std::vector<std::vector<int>> resultGrid(std::vector<std::vector<int>>& image,
                                           int threshold);
};

}  // namespace problem_3030
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_GRID_OF_REGION_AVERAGE_H_
