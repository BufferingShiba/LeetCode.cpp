#ifndef LEETCODE_PROBLEMS_FIND_WORDS_THAT_CAN_BE_FORMED_BY_CHARACTERS_H__
#define LEETCODE_PROBLEMS_FIND_WORDS_THAT_CAN_BE_FORMED_BY_CHARACTERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1160 {

using Func = std::function<int(std::vector<std::string>&, std::string)>;

class FindWordsThatCanBeFormedByCharactersSolution
    : public SolutionBase<Func> {
 public:
  FindWordsThatCanBeFormedByCharactersSolution();

  int countCharacters(std::vector<std::string>& words, std::string chars);
};

}  // namespace leetcode::problem_1160

#endif  // LEETCODE_PROBLEMS_FIND_WORDS_THAT_CAN_BE_FORMED_BY_CHARACTERS_H__
