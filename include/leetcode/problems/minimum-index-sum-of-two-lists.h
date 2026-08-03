#ifndef LEETCODE_PROBLEMS_MINIMUM_INDEX_SUM_OF_TWO_LISTS_H__
#define LEETCODE_PROBLEMS_MINIMUM_INDEX_SUM_OF_TWO_LISTS_H__

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_599 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&, std::vector<std::string>&)>;

class MinimumIndexSumOfTwoListsSolution : public SolutionBase<Func> {
 public:
  MinimumIndexSumOfTwoListsSolution();
  std::vector<std::string> findRestaurant(std::vector<std::string>& list1,
                                          std::vector<std::string>& list2);
};

}  // namespace problem_599
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_INDEX_SUM_OF_TWO_LISTS_H__
