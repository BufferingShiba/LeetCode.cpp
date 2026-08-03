#ifndef LEETCODE_PROBLEMS_ALPHABET_BOARD_PATH_H__
#define LEETCODE_PROBLEMS_ALPHABET_BOARD_PATH_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1138 {

using Func = std::function<std::string(std::string)>;

class AlphabetBoardPathSolution : public SolutionBase<Func> {
public:
    AlphabetBoardPathSolution();
    std::string alphabetBoardPath(std::string target);
};

}  // namespace leetcode::problem_1138

#endif  // LEETCODE_PROBLEMS_ALPHABET_BOARD_PATH_H__
