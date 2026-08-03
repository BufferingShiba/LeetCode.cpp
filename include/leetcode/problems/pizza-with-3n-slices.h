#ifndef LEETCODE_PROBLEMS_PIZZA_WITH_3N_SLICES_H__
#define LEETCODE_PROBLEMS_PIZZA_WITH_3N_SLICES_H__

#include <vector>
#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1388 {

using Func = std::function<int(std::vector<int>&)>;

class PizzaWith3nSlicesSolution : public SolutionBase<Func> {
 public:
  PizzaWith3nSlicesSolution();

  int maxSizeSlices(std::vector<int>& slices);
};

}  // namespace problem_1388
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PIZZA_WITH_3N_SLICES_H__
