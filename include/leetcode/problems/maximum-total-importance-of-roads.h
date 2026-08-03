#ifndef LEETCODE_MAXIMUM_TOTAL_IMPORTANCE_OF_ROADS_H__
#define LEETCODE_MAXIMUM_TOTAL_IMPORTANCE_OF_ROADS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2285 {

using Func = std::function<long long(int, std::vector<std::vector<int>>&)>;

class MaximumTotalImportanceOfRoadsSolution : public SolutionBase<Func> {
 public:
  MaximumTotalImportanceOfRoadsSolution();

  long long maximumImportance(int n, std::vector<std::vector<int>>& roads);
};

}  // namespace problem_2285
}  // namespace leetcode

#endif  // LEETCODE_MAXIMUM_TOTAL_IMPORTANCE_OF_ROADS_H__
