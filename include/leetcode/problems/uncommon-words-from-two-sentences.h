#ifndef LEETCODE_PROBLEMS_UNCOMMON_WORDS_FROM_TWO_SENTENCES_H__
#define LEETCODE_PROBLEMS_UNCOMMON_WORDS_FROM_TWO_SENTENCES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_884 {

using Func = std::function<std::vector<std::string>(std::string, std::string)>;

class UncommonWordsFromTwoSentencesSolution
    : public SolutionBase<Func> {
 public:
  UncommonWordsFromTwoSentencesSolution();

  std::vector<std::string> uncommonFromSentences(std::string s1,
                                                 std::string s2);
};

}  // namespace problem_884
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNCOMMON_WORDS_FROM_TWO_SENTENCES_H__
