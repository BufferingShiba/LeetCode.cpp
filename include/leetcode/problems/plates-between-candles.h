#ifndef LEETCODE_PROBLEMS_PLATES_BETWEEN_CANDLES_H__
#define LEETCODE_PROBLEMS_PLATES_BETWEEN_CANDLES_H__

#include <functional>
#include <vector>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2055 {

using Func = std::function<std::vector<int>(std::string, std::vector<std::vector<int>>&)>;

class PlatesBetweenCandlesSolution : public SolutionBase<Func> {
public:
    PlatesBetweenCandlesSolution();

    std::vector<int> platesBetweenCandles(std::string s, std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_2055

#endif  // LEETCODE_PROBLEMS_PLATES_BETWEEN_CANDLES_H__
