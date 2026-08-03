#ifndef LEETCODE_PROBLEMS_REACHING_POINTS_H__
#define LEETCODE_PROBLEMS_REACHING_POINTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_780 {

using Func = std::function<bool(int, int, int, int)>;

class ReachingPointsSolution : public SolutionBase<Func> {
 public:
  ReachingPointsSolution();

  bool reachingPoints(int sx, int sy, int tx, int ty);
};

}  // namespace problem_780
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REACHING_POINTS_H__
