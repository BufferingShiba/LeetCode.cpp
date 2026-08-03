#ifndef LEETCODE_PROBLEMS_SELLING_PIECES_OF_WOOD_H__
#define LEETCODE_PROBLEMS_SELLING_PIECES_OF_WOOD_H__

#include <vector>
#include <string>
#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_2312 {

using Func = std::function<long long(int, int, std::vector<std::vector<int>>&)>;

class SellingPiecesOfWoodSolution : public SolutionBase<Func> {
public:
    SellingPiecesOfWoodSolution();

    long long sellingWood(int m, int n, std::vector<std::vector<int>>& prices);
};

}  // namespace leetcode::problem_2312

#endif  // LEETCODE_PROBLEMS_SELLING_PIECES_OF_WOOD_H__
