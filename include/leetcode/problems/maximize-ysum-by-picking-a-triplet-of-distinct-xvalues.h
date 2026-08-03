#ifndef LEETCODE_PROBLEMS_MAXIMIZE_YSUM_BY_PICKING_A_TRIPLET_OF_DISTINCT_XVALUES_H__
#define LEETCODE_PROBLEMS_MAXIMIZE_YSUM_BY_PICKING_A_TRIPLET_OF_DISTINCT_XVALUES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3572 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MaximizeYsumByPickingATripletOfDistinctXvaluesSolution
    : public SolutionBase<Func> {
 public:
  MaximizeYsumByPickingATripletOfDistinctXvaluesSolution();

  int maxSumDistinctTriplet(std::vector<int>& x, std::vector<int>& y);
};

}  // namespace problem_3572
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_YSUM_BY_PICKING_A_TRIPLET_OF_DISTINCT_XVALUES_H__
