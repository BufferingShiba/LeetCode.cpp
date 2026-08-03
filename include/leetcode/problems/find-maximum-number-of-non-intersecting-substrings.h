#ifndef LEETCODE_PROBLEMS_FIND_MAXIMUM_NUMBER_OF_NON_INTERSECTING_SUBSTRINGS_H
#define LEETCODE_PROBLEMS_FIND_MAXIMUM_NUMBER_OF_NON_INTERSECTING_SUBSTRINGS_H

#include "leetcode/core.h"

#include <string>

namespace leetcode {
namespace problem_3557 {

using Func = std::function<int(std::string)>;

class FindMaximumNumberOfNonIntersectingSubstringsSolution : public SolutionBase<Func> {
 public:
  FindMaximumNumberOfNonIntersectingSubstringsSolution();

  int maxSubstrings(std::string word);
};

}  // namespace problem_3557
}  // namespace leetcode

#endif
