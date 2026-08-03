#ifndef LEETCODE_PROBLEMS_2343_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H__
#define LEETCODE_PROBLEMS_2343_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2343 {

using Func = std::function<std::vector<int>(std::vector<std::string>&,
                                            std::vector<std::vector<int>>&)>;

class QueryKthSmallestTrimmedNumberSolution
    : public SolutionBase<Func> {
 public:
  QueryKthSmallestTrimmedNumberSolution();

  std::vector<int> smallestTrimmedNumbers(
      std::vector<std::string>& nums, std::vector<std::vector<int>>& queries) {
    return getSolution()(nums, queries);
  }
};

}  // namespace problem_2343
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_2343_QUERY_KTH_SMALLEST_TRIMMED_NUMBER_H__
