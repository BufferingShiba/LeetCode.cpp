#ifndef LEETCODE_PROBLEMS_FIND_LONGEST_SPECIAL_SUBSTRING_THAT_OCCURS_THRICE_I_H_
#define LEETCODE_PROBLEMS_FIND_LONGEST_SPECIAL_SUBSTRING_THAT_OCCURS_THRICE_I_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2981 {

using Func = std::function<int(std::string)>;

class FindLongestSpecialSubstringThatOccursThriceISolution : public SolutionBase<Func> {
 public:
  FindLongestSpecialSubstringThatOccursThriceISolution();
  int maximumLength(std::string s);
};

}  // namespace problem_2981
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_LONGEST_SPECIAL_SUBSTRING_THAT_OCCURS_THRICE_I_H_
