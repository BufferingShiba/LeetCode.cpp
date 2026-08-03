#ifndef LEETCODE_PROBLEMS_PROCESS_STRING_WITH_SPECIAL_OPERATIONS_II_H__
#define LEETCODE_PROBLEMS_PROCESS_STRING_WITH_SPECIAL_OPERATIONS_II_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3614 {

using Func = std::function<char(std::string, long long)>;

class ProcessStringWithSpecialOperationsIiSolution
    : public SolutionBase<Func> {
 public:
  ProcessStringWithSpecialOperationsIiSolution();

  char processStr(std::string s, long long k);
};

}  // namespace problem_3614
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PROCESS_STRING_WITH_SPECIAL_OPERATIONS_II_H__
