#ifndef LEETCODE_PROBLEM_927_H
#define LEETCODE_PROBLEM_927_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_927 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ThreeEqualPartsSolution : public SolutionBase<Func> {
 public:
  ThreeEqualPartsSolution();
  std::vector<int> threeEqualParts(std::vector<int>& arr);
};

}  // namespace problem_927
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_927_H
