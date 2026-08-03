#ifndef LEETCODE_PROBLEMS_COUNT_DIGIT_APPEARANCES_H__
#define LEETCODE_PROBLEMS_COUNT_DIGIT_APPEARANCES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3895 {

using Func = std::function<int(std::vector<int>&, int)>;

class CountDigitAppearancesSolution : public SolutionBase<Func> {
public:
    CountDigitAppearancesSolution();

    int countDigitOccurrences(std::vector<int>& nums, int digit);
};

}  // namespace leetcode::problem_3895

#endif  // LEETCODE_PROBLEMS_COUNT_DIGIT_APPEARANCES_H__
