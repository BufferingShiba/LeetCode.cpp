#ifndef LEETCODE_PROBLEMS_SUM_OF_K_MIRROR_NUMBERS_H__
#define LEETCODE_PROBLEMS_SUM_OF_K_MIRROR_NUMBERS_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_2081 {

using Func = std::function<long long(int, int)>;

class SumOfKMirrorNumbersSolution : public SolutionBase<Func> {
 public:
  SumOfKMirrorNumbersSolution();

  long long kMirror(int k, int n);
};

}  // namespace problem_2081
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_K_MIRROR_NUMBERS_H__
