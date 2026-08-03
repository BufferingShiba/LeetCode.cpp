#ifndef LEETCODE_PROBLEMS_COORDINATE_WITH_MAXIMUM_NETWORK_QUALITY_H__defined
#define LEETCODE_PROBLEMS_COORDINATE_WITH_MAXIMUM_NETWORK_QUALITY_H__defined

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1620 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&, int)>;

class CoordinateWithMaximumNetworkQualitySolution : public SolutionBase<Func> {
 public:
  CoordinateWithMaximumNetworkQualitySolution();
  std::vector<int> bestCoordinate(std::vector<std::vector<int>>& towers, int radius);
};

}  // namespace problem_1620
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COORDINATE_WITH_MAXIMUM_NETWORK_QUALITY_H__defined
