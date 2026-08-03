#ifndef LEETCODE_PROBLEMS_COUNT_GOOD_INTEGERS_IN_A_RANGE_H__
#define LEETCODE_PROBLEMS_COUNT_GOOD_INTEGERS_IN_A_RANGE_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_3966 {

using Func = std::function<long long(long long, long long, int)>;

class CountGoodIntegersInARangeSolution : public SolutionBase<Func> {
 public:
  CountGoodIntegersInARangeSolution();

  long long goodIntegers(long long l, long long r, int k);
};

}  // namespace problem_3966
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_GOOD_INTEGERS_IN_A_RANGE_H__
