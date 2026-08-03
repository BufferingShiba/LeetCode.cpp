#ifndef LEETCODE_PROBLEM_SHIFT_DISTANCE_BETWEEN_TWO_STRINGS_H_
#define LEETCODE_PROBLEM_SHIFT_DISTANCE_BETWEEN_TWO_STRINGS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3361 {

using Func = std::function<long long(std::string, std::string, std::vector<int>&, std::vector<int>&)>;

class ShiftDistanceBetweenTwoStringsSolution : public SolutionBase<Func> {
 public:
  ShiftDistanceBetweenTwoStringsSolution();

  long long shiftDistance(std::string s, std::string t, std::vector<int>& nextCost, std::vector<int>& previousCost);
};

}  // namespace problem_3361
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_SHIFT_DISTANCE_BETWEEN_TWO_STRINGS_H_
