#ifndef LEETCODE_PROBLEMS_NUMBER_OF_VALID_WORDS_IN_A_SENTENCE_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_VALID_WORDS_IN_A_SENTENCE_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2047 {

using Func = std::function<int(std::string)>;

class NumberOfValidWordsInASentenceSolution
    : public SolutionBase<Func> {
 public:
  NumberOfValidWordsInASentenceSolution();
  int countValidWords(std::string sentence);
};

}  // namespace problem_2047
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_VALID_WORDS_IN_A_SENTENCE_H_
