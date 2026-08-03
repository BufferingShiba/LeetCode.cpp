#ifndef LEETCODE_PROBLEMS_SUBSTRINGS_OF_SIZE_THREE_WITH_DISTINCT_CHARACTERS_H_
#define LEETCODE_PROBLEMS_SUBSTRINGS_OF_SIZE_THREE_WITH_DISTINCT_CHARACTERS_H_

#include "leetcode/core.h"
#include <string>

namespace leetcode {
namespace problem_1876 {

using Func = std::function<int(std::string)>;

class SubstringsOfSizeThreeWithDistinctCharactersSolution : public SolutionBase<Func> {
 public:
  SubstringsOfSizeThreeWithDistinctCharactersSolution();
  int countGoodSubstrings(std::string s);
};

}  // namespace problem_1876
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUBSTRINGS_OF_SIZE_THREE_WITH_DISTINCT_CHARACTERS_H_
