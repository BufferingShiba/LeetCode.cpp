#ifndef LEETCODE_PROBLEMS_FIND_MAXIMUM_REMOVALS_FROM_SOURCE_STRING_H__
#define LEETCODE_PROBLEMS_FIND_MAXIMUM_REMOVALS_FROM_SOURCE_STRING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3316 {

using Func = std::function<int(std::string, std::string, std::vector<int>&)>;

class FindMaximumRemovalsFromSourceStringSolution
    : public SolutionBase<Func> {
 public:
  int maxRemovals(std::string source, std::string pattern,
                  std::vector<int>& targetIndices);

  FindMaximumRemovalsFromSourceStringSolution();
};

}  // namespace leetcode::problem_3316

#endif  // LEETCODE_PROBLEMS_FIND_MAXIMUM_REMOVALS_FROM_SOURCE_STRING_H__
