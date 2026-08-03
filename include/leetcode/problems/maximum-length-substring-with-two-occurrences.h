#ifndef LEETCODE_PROBLEMS_MAXIMUM_LENGTH_SUBSTRING_WITH_TWO_OCCURRENCES_H__
#define LEETCODE_PROBLEMS_MAXIMUM_LENGTH_SUBSTRING_WITH_TWO_OCCURRENCES_H__

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3090 {

using Func = std::function<int(std::string)>;

class MaximumLengthSubstringWithTwoOccurrencesSolution
    : public SolutionBase<Func> {
 public:
  MaximumLengthSubstringWithTwoOccurrencesSolution();

  int maximumLengthSubstring(std::string s);
};

}  // namespace problem_3090
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_LENGTH_SUBSTRING_WITH_TWO_OCCURRENCES_H__
