#ifndef LEETCODE_PROBLEMS_COMPLEMENT_OF_BASE_10_INTEGER_H__
#define LEETCODE_PROBLEMS_COMPLEMENT_OF_BASE_10_INTEGER_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_1009 {

using Func = std::function<int(int)>;

class ComplementOfBase10IntegerSolution
    : public SolutionBase<Func> {
 public:
  ComplementOfBase10IntegerSolution();

  int bitwiseComplement(int n);
};

}  // namespace problem_1009
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COMPLEMENT_OF_BASE_10_INTEGER_H__
