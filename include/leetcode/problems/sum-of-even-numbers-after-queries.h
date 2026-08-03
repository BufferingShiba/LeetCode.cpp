#ifndef LEETCODE_PROBLEMS_SUM_OF_EVEN_NUMBERS_AFTER_QUERIES_H__
#define LEETCODE_PROBLEMS_SUM_OF_EVEN_NUMBERS_AFTER_QUERIES_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_985 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<std::vector<int>>&)>;

class SumOfEvenNumbersAfterQueriesSolution : public SolutionBase<Func> {
 public:
  SumOfEvenNumbersAfterQueriesSolution();
  std::vector<int> sumEvenAfterQueries(std::vector<int>& nums,
                                       std::vector<std::vector<int>>& queries);
};

}  // namespace problem_985
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_EVEN_NUMBERS_AFTER_QUERIES_H__
