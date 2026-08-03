#ifndef LEETCODE_PROBLEMS_FIND_THE_K_OR_OF_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_THE_K_OR_OF_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2917 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindTheKOrOfAnArraySolution : public SolutionBase<Func> {
 public:
  FindTheKOrOfAnArraySolution();

  int findKOr(std::vector<int>& nums, int k);
};

}  // namespace problem_2917
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_K_OR_OF_AN_ARRAY_H__
