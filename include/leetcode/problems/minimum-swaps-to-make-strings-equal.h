#ifndef LEETCODE_PROBLEM_1247_H_
#define LEETCODE_PROBLEM_1247_H_

#include "leetcode/core.h"

namespace leetcode::problem_1247 {

using Func = std::function<int(std::string, std::string)>;

class MinimumSwapsToMakeStringsEqualSolution : public SolutionBase<Func> {
public:
    int minimumSwap(std::string s1, std::string s2);

    MinimumSwapsToMakeStringsEqualSolution();
};

}  // namespace leetcode::problem_1247

#endif  // LEETCODE_PROBLEM_1247_H_
