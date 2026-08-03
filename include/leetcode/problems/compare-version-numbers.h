#ifndef LEETCODE_PROBLEMS_COMPARE_VERSION_NUMBERS_H
#define LEETCODE_PROBLEMS_COMPARE_VERSION_NUMBERS_H

#include "leetcode/core.h"

namespace leetcode::problem_165 {

using Func = std::function<int(const std::string&, const std::string&)>;

class CompareVersionNumbersSolution : public SolutionBase<Func> {
public:
    CompareVersionNumbersSolution();
};

}  // namespace leetcode::problem_165

#endif  // LEETCODE_PROBLEMS_COMPARE_VERSION_NUMBERS_H
