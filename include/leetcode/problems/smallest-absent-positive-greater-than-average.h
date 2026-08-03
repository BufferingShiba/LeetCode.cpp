#ifndef LEETCODE_PROBLEMS_SMALLEST_ABSENT_POSITIVE_GREATER_THAN_AVERAGE_H__
#define LEETCODE_PROBLEMS_SMALLEST_ABSENT_POSITIVE_GREATER_THAN_AVERAGE_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3678 {

using Func = std::function<int(std::vector<int>&)>;

class SmallestAbsentPositiveGreaterThanAverageSolution
    : public SolutionBase<Func> {
 public:
  SmallestAbsentPositiveGreaterThanAverageSolution();

  int smallestAbsent(std::vector<int>& nums);
};

}  // namespace problem_3678
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_ABSENT_POSITIVE_GREATER_THAN_AVERAGE_H__
