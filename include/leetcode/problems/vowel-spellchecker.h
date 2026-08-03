#ifndef LEETCODE_PROBLEMS_VOWEL_SPELLCHECKER_H__
#define LEETCODE_PROBLEMS_VOWEL_SPELLCHECKER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_966 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&, std::vector<std::string>&)>;

class VowelSpellcheckerSolution : public SolutionBase<Func> {
 public:
  VowelSpellcheckerSolution();

  std::vector<std::string> spellchecker(std::vector<std::string>& wordlist,
                                        std::vector<std::string>& queries);
};

}  // namespace leetcode::problem_966

#endif  // LEETCODE_PROBLEMS_VOWEL_SPELLCHECKER_H__
