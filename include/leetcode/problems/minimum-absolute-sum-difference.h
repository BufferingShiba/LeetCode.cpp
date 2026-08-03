#ifndef LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H__
#define LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1818 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MinimumAbsoluteSumDifferenceSolution : public SolutionBase<Func> {
 public:
  MinimumAbsoluteSumDifferenceSolution();
};

}  // namespace problem_1818
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H__
