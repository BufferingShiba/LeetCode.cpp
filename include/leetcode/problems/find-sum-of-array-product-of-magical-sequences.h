#ifndef LEETCODE_PROBLEMS_FIND_SUM_OF_ARRAY_PRODUCT_OF_MAGICAL_SEQUENCES_H_
#define LEETCODE_PROBLEMS_FIND_SUM_OF_ARRAY_PRODUCT_OF_MAGICAL_SEQUENCES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3539 {

using Func = std::function<int(int, int, std::vector<int>&)>;

class FindSumOfArrayProductOfMagicalSequencesSolution : public SolutionBase<Func> {
 public:
  FindSumOfArrayProductOfMagicalSequencesSolution();

  int magicalSum(int m, int k, std::vector<int>& nums);
};

}  // namespace problem_3539
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_SUM_OF_ARRAY_PRODUCT_OF_MAGICAL_SEQUENCES_H_
