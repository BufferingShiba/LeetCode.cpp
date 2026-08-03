#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_SUBSEQUENCES_AFTER_ONE_INSERTING_H_
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_SUBSEQUENCES_AFTER_ONE_INSERTING_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_3628 {

using Func = std::function<long long(const std::string&)>;

class MaximumNumberOfSubsequencesAfterOneInsertingSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfSubsequencesAfterOneInsertingSolution();
  long long numOfSubsequences(const std::string& s);
};

}  // namespace leetcode::problem_3628

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_SUBSEQUENCES_AFTER_ONE_INSERTING_H_
