#ifndef LEETCODE_PROBLEMS_MAXIMAL_SQUARE_H__
#define LEETCODE_PROBLEMS_MAXIMAL_SQUARE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_221 {

using Func = std::function<int(std::vector<std::vector<char>>&)>;

class MaximalSquareSolution : public SolutionBase<Func> {
 public:
  MaximalSquareSolution();

  // Public method matching the problem signature.
  int maximalSquare(std::vector<std::vector<char>>& matrix);
};

}  // namespace problem_221
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMAL_SQUARE_H__
