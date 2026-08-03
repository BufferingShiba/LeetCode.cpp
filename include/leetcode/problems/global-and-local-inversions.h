#ifndef LEETCODE_PROBLEMS_GLOBAL_AND_LOCAL_INVERSIONS_H_
#define LEETCODE_PROBLEMS_GLOBAL_AND_LOCAL_INVERSIONS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_775 {

using Func = std::function<bool(std::vector<int>&)>;

class GlobalAndLocalInversionsSolution : public SolutionBase<Func> {
 public:
  GlobalAndLocalInversionsSolution();

  bool isIdealPermutation(std::vector<int>& nums);
};

}  // namespace problem_775
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GLOBAL_AND_LOCAL_INVERSIONS_H_
