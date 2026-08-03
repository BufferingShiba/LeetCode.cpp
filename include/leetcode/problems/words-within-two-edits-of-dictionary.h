#ifndef LEETCODE_PROBLEMS_WORDS_WITHIN_TWO_EDITS_OF_DICTIONARY_H__
#define LEETCODE_PROBLEMS_WORDS_WITHIN_TWO_EDITS_OF_DICTIONARY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2452 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&, std::vector<std::string>&)>;

class WordsWithinTwoEditsOfDictionarySolution
    : public SolutionBase<Func> {
 public:
  WordsWithinTwoEditsOfDictionarySolution();

  std::vector<std::string> twoEditWords(
      std::vector<std::string>& queries,
      std::vector<std::string>& dictionary);
};

}  // namespace problem_2452
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_WORDS_WITHIN_TWO_EDITS_OF_DICTIONARY_H__
