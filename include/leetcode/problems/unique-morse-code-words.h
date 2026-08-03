#ifndef LEETCODE_PROBLEMS_UNIQUE_MORSE_CODE_WORDS_H__
#define LEETCODE_PROBLEMS_UNIQUE_MORSE_CODE_WORDS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_804 {

using Func = std::function<int(std::vector<std::string>&)>;

class UniqueMorseCodeWordsSolution : public SolutionBase<Func> {
 public:
  UniqueMorseCodeWordsSolution();

  int uniqueMorseRepresentations(std::vector<std::string>& words);
};

}  // namespace problem_804
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNIQUE_MORSE_CODE_WORDS_H__
