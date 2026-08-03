#ifndef LEETCODE_PROBLEMS_MAXIMUM_POINTS_INSIDE_THE_SQUARE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_POINTS_INSIDE_THE_SQUARE_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3143 {

using Func = std::function<int(std::vector<std::vector<int>>&, std::string&)>;

class MaximumPointsInsideTheSquareSolution : public SolutionBase<Func> {
 public:
  MaximumPointsInsideTheSquareSolution();

  int maxPointsInsideSquare(std::vector<std::vector<int>>& points, std::string s);
};

}  // namespace problem_3143
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_POINTS_INSIDE_THE_SQUARE_H__
