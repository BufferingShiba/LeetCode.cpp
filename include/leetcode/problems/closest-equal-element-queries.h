#ifndef LEETCODE_PROBLEMS_CLOSEST_EQUAL_ELEMENT_QUERIES_H__
#define LEETCODE_PROBLEMS_CLOSEST_EQUAL_ELEMENT_QUERIES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3488 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class ClosestEqualElementQueriesSolution
    : public SolutionBase<Func> {
 public:
  ClosestEqualElementQueriesSolution();

  std::vector<int> solveQueries(std::vector<int>& nums,
                                std::vector<int>& queries);
};

}  // namespace problem_3488
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CLOSEST_EQUAL_ELEMENT_QUERIES_H__
