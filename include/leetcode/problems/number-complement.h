#ifndef LEETCODE_PROBLEMS_NUMBER_COMPLEMENT_H__
#define LEETCODE_PROBLEMS_NUMBER_COMPLEMENT_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_476 {

using Func = std::function<int(int)>;

class NumberComplementSolution : public SolutionBase<Func> {
public:
    NumberComplementSolution();

    int findComplement(int num);
};

}  // namespace problem_476
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_COMPLEMENT_H__
