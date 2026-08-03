#ifndef LEETCODE_PROBLEMS_ANT_ON_THE_BOUNDARY_H_
#define LEETCODE_PROBLEMS_ANT_ON_THE_BOUNDARY_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3028 {

using Func = std::function<int(std::vector<int>&)>;

class AntOnTheBoundarySolution : public SolutionBase<Func> {
 public:
  AntOnTheBoundarySolution();

  int returnToBoundaryCount(std::vector<int>& nums);
};

}  // namespace problem_3028
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ANT_ON_THE_BOUNDARY_H_
