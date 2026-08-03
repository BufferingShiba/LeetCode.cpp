#ifndef LEETCODE_PROBLEMS_NUMBER_OF_LASER_BEAMS_IN_A_BANK_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_LASER_BEAMS_IN_A_BANK_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2125 {

using Func = std::function<int(std::vector<std::string>&)>;

class NumberOfLaserBeamsInABankSolution
    : public SolutionBase<Func> {
public:
    NumberOfLaserBeamsInABankSolution();
    int numberOfBeams(std::vector<std::string>& bank);
};

}  // namespace leetcode::problem_2125

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_LASER_BEAMS_IN_A_BANK_H__
