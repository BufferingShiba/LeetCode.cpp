#ifndef LEETCODE_PROBLEMS_CHECK_IF_N_AND_ITS_DOUBLE_EXIST_H__
#define LEETCODE_PROBLEMS_CHECK_IF_N_AND_ITS_DOUBLE_EXIST_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1346 {

using Func = std::function<bool(std::vector<int>&)>;

class CheckIfNAndItsDoubleExistSolution : public SolutionBase<Func> {
 public:
  CheckIfNAndItsDoubleExistSolution();

  bool checkIfExist(std::vector<int>& arr) { return getSolution()(arr); }
};

}  // namespace problem_1346
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_N_AND_ITS_DOUBLE_EXIST_H__
