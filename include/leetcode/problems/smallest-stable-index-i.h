#ifndef LEETCODE_PROBLEMS_SMALLEST_STABLE_INDEX_I_H_
#define LEETCODE_PROBLEMS_SMALLEST_STABLE_INDEX_I_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3903 {

using Func = std::function<int(std::vector<int>&, int)>;

class SmallestStableIndexISolution : public SolutionBase<Func> {
 public:
  SmallestStableIndexISolution();

  int firstStableIndex(std::vector<int>& nums, int k);
};

}  // namespace problem_3903
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_STABLE_INDEX_I_H_
