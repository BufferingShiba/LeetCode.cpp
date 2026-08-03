#ifndef LEETCODE_PROBLEMS_SNAKE_IN_MATRIX_H__
#define LEETCODE_PROBLEMS_SNAKE_IN_MATRIX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3248 {

using Func = std::function<int(int, std::vector<std::string>&)>;

class SnakeInMatrixSolution : public SolutionBase<Func> {
 public:
  SnakeInMatrixSolution();
  int finalPositionOfSnake(int n, std::vector<std::string>& commands);
};

}  // namespace problem_3248
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SNAKE_IN_MATRIX_H__
