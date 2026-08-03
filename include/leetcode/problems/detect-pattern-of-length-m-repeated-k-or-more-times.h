#ifndef LEETCODE_PROBLEMS_DETECT_PATTERN_OF_LENGTH_M_REPEATED_K_OR_MORE_TIMES_H__
#define LEETCODE_PROBLEMS_DETECT_PATTERN_OF_LENGTH_M_REPEATED_K_OR_MORE_TIMES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1566 {

using Func = std::function<bool(std::vector<int>&, int, int)>;

class DetectPatternOfLengthMRepeatedKOrMoreTimesSolution
    : public SolutionBase<Func> {
 public:
  DetectPatternOfLengthMRepeatedKOrMoreTimesSolution();

  bool containsPattern(std::vector<int>& arr, int m, int k);
};

}  // namespace problem_1566
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DETECT_PATTERN_OF_LENGTH_M_REPEATED_K_OR_MORE_TIMES_H__
