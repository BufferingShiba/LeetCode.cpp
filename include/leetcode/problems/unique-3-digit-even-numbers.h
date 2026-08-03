#ifndef LEETCODE_PROBLEMS_UNIQUE_3_DIGIT_EVEN_NUMBERS_H__
#define LEETCODE_PROBLEMS_UNIQUE_3_DIGIT_EVEN_NUMBERS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3483 {

using Func = std::function<int(std::vector<int>&)>;

class Unique3DigitEvenNumbersSolution
    : public SolutionBase<Func> {
public:
    Unique3DigitEvenNumbersSolution();

    // 原题接口
    int totalNumbers(std::vector<int>& digits);
};

}  // namespace leetcode::problem_3483

#endif  // LEETCODE_PROBLEMS_UNIQUE_3_DIGIT_EVEN_NUMBERS_H__
