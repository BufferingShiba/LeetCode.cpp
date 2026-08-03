#ifndef LEETCODE_PROBLEMS_MOVE_ZEROES_H_
#define LEETCODE_PROBLEMS_MOVE_ZEROES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_283 {

using Func = std::function<void(std::vector<int>&)>;

class MoveZeroesSolution : public SolutionBase<Func> {
 public:
  MoveZeroesSolution();

  void moveZeroes(std::vector<int>& nums);
};

}  // namespace problem_283
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MOVE_ZEROES_H_
