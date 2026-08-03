#ifndef LEETCODE_PROBLEMS_INCREMENTAL_EVEN_WEIGHTED_CYCLE_QUERIES_H_
#define LEETCODE_PROBLEMS_INCREMENTAL_EVEN_WEIGHTED_CYCLE_QUERIES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3887 {

using Func = std::function<int(int, std::vector<std::vector<int>>&)>;

class IncrementalEvenWeightedCycleQueriesSolution : public SolutionBase<Func> {
 public:
  IncrementalEvenWeightedCycleQueriesSolution();
  int numberOfEdgesAdded(int n, std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3887
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INCREMENTAL_EVEN_WEIGHTED_CYCLE_QUERIES_H_
