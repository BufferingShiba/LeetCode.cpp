#ifndef LEETCODE_PROBLEMS_MINIMUM_ARRAY_END_H__
#define LEETCODE_PROBLEMS_MINIMUM_ARRAY_END_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3133 {

using Func = std::function<long long(int, int)>;

class MinimumArrayEndSolution : public SolutionBase<Func> {
 public:
  MinimumArrayEndSolution();

  long long minEnd(int n, int x);
};

}  // namespace problem_3133
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_ARRAY_END_H__
