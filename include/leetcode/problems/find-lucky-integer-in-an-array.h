#ifndef LEETCODE_PROBLEMS_FIND_LUCKY_INTEGER_IN_AN_ARRAY_H_
#define LEETCODE_PROBLEMS_FIND_LUCKY_INTEGER_IN_AN_ARRAY_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1394 {

using Func = std::function<int(std::vector<int>&)>;

class FindLuckyIntegerInAnArraySolution
    : public SolutionBase<Func> {
 public:
  FindLuckyIntegerInAnArraySolution();

  int findLucky(std::vector<int>& arr);
};

}  // namespace problem_1394
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_LUCKY_INTEGER_IN_AN_ARRAY_H_
