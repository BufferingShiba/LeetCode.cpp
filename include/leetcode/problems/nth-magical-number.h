#ifndef LEETCODE_PROBLEMS_NTH_MAGICAL_NUMBER_H__
#define LEETCODE_PROBLEMS_NTH_MAGICAL_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_878 {

using Func = std::function<int(int, int, int)>;

class NthMagicalNumberSolution : public SolutionBase<Func> {
 public:
  NthMagicalNumberSolution();
  int nthMagicalNumber(int n, int a, int b);
};

}  // namespace problem_878
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NTH_MAGICAL_NUMBER_H__
