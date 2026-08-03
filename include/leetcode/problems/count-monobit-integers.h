#ifndef LEETCODE_PROBLEM_COUNT_MONOBIT_INTEGERS_H
#define LEETCODE_PROBLEM_COUNT_MONOBIT_INTEGERS_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3827 {

using Func = std::function<int(int)>;

class CountMonobitIntegersSolution : public SolutionBase<Func> {
 public:
  CountMonobitIntegersSolution();

  int countMonobit(int n);
};

}  // namespace problem_3827
}  // namespace leetcode

#endif
