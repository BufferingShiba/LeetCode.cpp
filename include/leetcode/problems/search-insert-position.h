#ifndef LEETCODE_PROBLEMS_SEARCH_INSERT_POSITION_H__
#define LEETCODE_PROBLEMS_SEARCH_INSERT_POSITION_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_35 {

using Func = std::function<int(std::vector<int>&, int)>;

class SearchInsertPositionSolution : public SolutionBase<Func> {
 public:
  SearchInsertPositionSolution();

  int searchInsert(std::vector<int>& nums, int target);
};

}  // namespace problem_35
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SEARCH_INSERT_POSITION_H__
