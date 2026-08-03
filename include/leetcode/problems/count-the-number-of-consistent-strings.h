#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_CONSISTENT_STRINGS_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_CONSISTENT_STRINGS_H__

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1684 {

using Func = std::function<int(std::string, std::vector<std::string>&)>;

class CountTheNumberOfConsistentStringsSolution
    : public SolutionBase<Func> {
 public:
  int countConsistentStrings(std::string allowed, std::vector<std::string>& words);

  CountTheNumberOfConsistentStringsSolution();
};

}  // namespace leetcode::problem_1684

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_CONSISTENT_STRINGS_H__
