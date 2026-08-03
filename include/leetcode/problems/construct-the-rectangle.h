#ifndef LEETCODE_PROBLEMS_CONSTRUCT_THE_RECTANGLE_H_
#define LEETCODE_PROBLEMS_CONSTRUCT_THE_RECTANGLE_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_492 {

using Func = std::function<std::vector<int>(int)>;

class ConstructTheRectangleSolution : public SolutionBase<Func> {
 public:
  ConstructTheRectangleSolution();

  std::vector<int> constructRectangle(int area);
};

}  // namespace problem_492
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_THE_RECTANGLE_H_
