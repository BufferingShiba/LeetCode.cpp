#ifndef LEETCODE_PROBLEMS_PRIME_ARRANGEMENTS_H__
#define LEETCODE_PROBLEMS_PRIME_ARRANGEMENTS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1175 {

using Func = std::function<int(int)>;

class PrimeArrangementsSolution : public SolutionBase<Func> {
 public:
  PrimeArrangementsSolution();

  int numPrimeArrangements(int n);
};

}  // namespace problem_1175
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PRIME_ARRANGEMENTS_H__
