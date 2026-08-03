#ifndef LEETCODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_H__
#define LEETCODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_28 {

using FindTheIndexOfTheFirstOccurrenceInAStringFunc =
    std::function<int(std::string, std::string)>;

class FindTheIndexOfTheFirstOccurrenceInAStringSolution
    : public SolutionBase<FindTheIndexOfTheFirstOccurrenceInAStringFunc> {
 public:
  int strStr(std::string haystack, std::string needle);

  FindTheIndexOfTheFirstOccurrenceInAStringSolution();
};

}  // namespace problem_28
}  // namespace leetcode

#endif  // LEETCODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_H__
