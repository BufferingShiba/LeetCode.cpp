#ifndef LEETCODE_PROBLEMS_NUMBER_OF_SEGMENTS_IN_A_STRING_H
#define LEETCODE_PROBLEMS_NUMBER_OF_SEGMENTS_IN_A_STRING_H

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_434 {

using Func = std::function<int(std::string)>;

class NumberOfSegmentsInAStringSolution : public SolutionBase<Func> {
 public:
  NumberOfSegmentsInAStringSolution();
  int countSegments(std::string s);
};

}  // namespace problem_434
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_SEGMENTS_IN_A_STRING_H
