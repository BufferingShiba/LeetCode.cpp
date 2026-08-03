#ifndef LEETCODE_PROBLEMS_MINIMIZE_STRING_LENGTH_H__
#define LEETCODE_PROBLEMS_MINIMIZE_STRING_LENGTH_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_2716 {

using Func = std::function<int(std::string)>;

class MinimizeStringLengthSolution : public SolutionBase<Func> {
public:
    MinimizeStringLengthSolution();

    int minimizedStringLength(std::string s);
};

}  // namespace problem_2716
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMIZE_STRING_LENGTH_H__
