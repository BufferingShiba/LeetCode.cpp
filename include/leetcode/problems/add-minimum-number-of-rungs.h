#ifndef LEETCODE_PROBLEMS_ADD_MINIMUM_NUMBER_OF_RUNGS_H__
#define LEETCODE_PROBLEMS_ADD_MINIMUM_NUMBER_OF_RUNGS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1936 {

using Func = std::function<int(std::vector<int>&, int)>;

class AddMinimumNumberOfRungsSolution : public SolutionBase<Func> {
 public:
  AddMinimumNumberOfRungsSolution();
  int addRungs(std::vector<int>& rungs, int dist);
};

}  // namespace problem_1936
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ADD_MINIMUM_NUMBER_OF_RUNGS_H__
