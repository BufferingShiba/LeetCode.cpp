#pragma once

#include <string>
#include <functional>
#include "leetcode/core.h"

namespace leetcode::problem_3816 {

using Func = std::function<std::string(std::string)>;

class LexSmallestAfterDeletionSolution : public SolutionBase<Func> {
public:
    LexSmallestAfterDeletionSolution();

    std::string lexSmallestAfterDeletion(std::string s);
};

}  // namespace leetcode::problem_3816
