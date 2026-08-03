#pragma once

#include "leetcode/core.h"
#include <functional>

namespace leetcode::problem_397 {

using Func = std::function<int(int)>;

class IntegerReplacementSolution : public SolutionBase<Func> {
public:
    IntegerReplacementSolution();

    int integerReplacement(int n);
};

}  // namespace leetcode::problem_397
