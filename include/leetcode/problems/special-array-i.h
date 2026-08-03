#ifndef LEETCODE_PROBLEMS_SPECIAL_ARRAY_I_H__
#define LEETCODE_PROBLEMS_SPECIAL_ARRAY_I_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3151 {

using Func = std::function<bool(std::vector<int>&)>;

class SpecialArrayISolution : public SolutionBase<Func> {
 public:
  SpecialArrayISolution();

  bool isArraySpecial(std::vector<int>& nums);
};

}  // namespace problem_3151
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPECIAL_ARRAY_I_H__
