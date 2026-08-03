#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_WORD_K_PERIODIC_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_WORD_K_PERIODIC_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3137 {

using Func = std::function<int(std::string, int)>;

class MinimumNumberOfOperationsToMakeWordKPeriodicSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfOperationsToMakeWordKPeriodicSolution();

  int minimumOperationsToMakeKPeriodic(std::string word, int k);
};

}  // namespace problem_3137
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_WORD_K_PERIODIC_H_
