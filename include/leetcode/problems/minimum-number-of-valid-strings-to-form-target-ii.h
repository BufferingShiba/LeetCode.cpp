#ifndef LEETCODE_PROBLEM_3292_H
#define LEETCODE_PROBLEM_3292_H

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3292 {

using Func = std::function<int(std::vector<std::string>&, std::string)>;

class MinimumNumberOfValidStringsToFormTargetIiSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfValidStringsToFormTargetIiSolution();
  int minValidStrings(std::vector<std::string>& words, std::string target);
};

}  // namespace problem_3292
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3292_H
