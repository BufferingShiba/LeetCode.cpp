#ifndef LEETCODE_PROBLEMS_NUMBER_OF_STRINGS_THAT_APPEAR_AS_SUBSTRINGS_IN_WORD_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_STRINGS_THAT_APPEAR_AS_SUBSTRINGS_IN_WORD_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1967 {

using Func = std::function<int(std::vector<std::string>&, std::string)>;

class NumberOfStringsThatAppearAsSubstringsInWordSolution
    : public SolutionBase<Func> {
 public:
  NumberOfStringsThatAppearAsSubstringsInWordSolution();

  int numOfStrings(std::vector<std::string>& patterns, std::string word);
};

}  // namespace problem_1967
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_STRINGS_THAT_APPEAR_AS_SUBSTRINGS_IN_WORD_H__
