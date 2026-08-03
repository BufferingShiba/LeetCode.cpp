#ifndef LEETCODE_PROBLEMS_FIND_THE_PREFIX_COMMON_ARRAY_OF_TWO_ARRAYS_H_
#define LEETCODE_PROBLEMS_FIND_THE_PREFIX_COMMON_ARRAY_OF_TWO_ARRAYS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2657 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class FindThePrefixCommonArrayOfTwoArraysSolution
    : public SolutionBase<Func> {
 public:
  FindThePrefixCommonArrayOfTwoArraysSolution();

  // 题目原方法：返回前缀公共数组
  std::vector<int> findThePrefixCommonArray(std::vector<int>& A,
                                            std::vector<int>& B);
};

}  // namespace problem_2657
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_PREFIX_COMMON_ARRAY_OF_TWO_ARRAYS_H_
