#ifndef LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_CAN_BE_REARRANGED_TO_CONTAIN_A_STRING_I_H__
#define LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_CAN_BE_REARRANGED_TO_CONTAIN_A_STRING_I_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_3297 {

using Func = std::function<long long(std::string, std::string)>;

class CountSubstringsThatCanBeRearrangedToContainAStringISolution
    : public SolutionBase<Func> {
 public:
  long long validSubstringCount(std::string word1, std::string word2);

  CountSubstringsThatCanBeRearrangedToContainAStringISolution();
};

}  // namespace leetcode::problem_3297

#endif  // LEETCODE_PROBLEMS_COUNT_SUBSTRINGS_THAT_CAN_BE_REARRANGED_TO_CONTAIN_A_STRING_I_H__
