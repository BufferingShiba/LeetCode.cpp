#ifndef LEETCODE_PROBLEMS_POSITIONS_OF_LARGE_GROUPS_H__
#define LEETCODE_PROBLEMS_POSITIONS_OF_LARGE_GROUPS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_830 {

using Func = std::function<std::vector<std::vector<int>>(const std::string&)>;

class PositionsOfLargeGroupsSolution : public SolutionBase<Func> {
 public:
  PositionsOfLargeGroupsSolution();

  std::vector<std::vector<int>> largeGroupPositions(const std::string& s) {
    return getSolution()(s);
  }
};

}  // namespace problem_830
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_POSITIONS_OF_LARGE_GROUPS_H__
