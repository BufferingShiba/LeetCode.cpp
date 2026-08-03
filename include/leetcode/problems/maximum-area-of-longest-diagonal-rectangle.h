// Copyright leetcode.cpp contributors
#ifndef LEETCODE_PROBLEMS_MAXIMUM_AREA_OF_LONGEST_DIAGONAL_RECTANGLE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_AREA_OF_LONGEST_DIAGONAL_RECTANGLE_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3000 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumAreaOfLongestDiagonalRectangleSolution
    : public SolutionBase<Func> {
 public:
  MaximumAreaOfLongestDiagonalRectangleSolution();

  int areaOfMaxDiagonal(std::vector<std::vector<int>>& dimensions);
};

}  // namespace problem_3000
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_AREA_OF_LONGEST_DIAGONAL_RECTANGLE_H__
