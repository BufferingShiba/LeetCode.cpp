#ifndef LEETCODE_PROBLEMS_DECRYPT_STRING_FROM_ALPHABET_TO_INTEGER_MAPPING_H__
#define LEETCODE_PROBLEMS_DECRYPT_STRING_FROM_ALPHABET_TO_INTEGER_MAPPING_H__

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1309 {

using Func = std::function<std::string(std::string)>;

class DecryptStringFromAlphabetToIntegerMappingSolution
    : public SolutionBase<Func> {
 public:
  DecryptStringFromAlphabetToIntegerMappingSolution();

  std::string freqAlphabets(std::string s);

  static std::vector<std::string> strategyNames();
};

}  // namespace leetcode::problem_1309

#endif  // LEETCODE_PROBLEMS_DECRYPT_STRING_FROM_ALPHABET_TO_INTEGER_MAPPING_H__
