#ifndef LEETCODE_PROBLEMS_NUMBER_OF_COMMON_FACTORS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_COMMON_FACTORS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2427 {

using Func = std::function<int(int, int)>;

class NumberOfCommonFactorsSolution : public SolutionBase<Func> {
 public:
  NumberOfCommonFactorsSolution();

  int commonFactors(int a, int b);
};

}  // namespace problem_2427
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_COMMON_FACTORS_H__
