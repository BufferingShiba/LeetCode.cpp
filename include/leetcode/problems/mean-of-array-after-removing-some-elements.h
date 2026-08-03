#ifndef LEETCODE_PROBLEMS_MEAN_OF_ARRAY_AFTER_REMOVING_SOME_ELEMENTS_H__
#define LEETCODE_PROBLEMS_MEAN_OF_ARRAY_AFTER_REMOVING_SOME_ELEMENTS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1619 {

using Func = std::function<double(std::vector<int>&)>;

class MeanOfArrayAfterRemovingSomeElementsSolution : public SolutionBase<Func> {
 public:
  MeanOfArrayAfterRemovingSomeElementsSolution();
};

}  // namespace problem_1619
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MEAN_OF_ARRAY_AFTER_REMOVING_SOME_ELEMENTS_H__
