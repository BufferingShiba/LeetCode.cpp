#ifndef LEETCODE_PROBLEMS_SPLIT_STRINGS_BY_SEPARATOR_H__
#define LEETCODE_PROBLEMS_SPLIT_STRINGS_BY_SEPARATOR_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2788 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&, char)>;

class SplitStringsBySeparatorSolution : public SolutionBase<Func> {
 public:
  SplitStringsBySeparatorSolution();

  std::vector<std::string> splitWordsBySeparator(std::vector<std::string>& words,
                                                  char separator);
};

}  // namespace leetcode::problem_2788

#endif  // LEETCODE_PROBLEMS_SPLIT_STRINGS_BY_SEPARATOR_H__
