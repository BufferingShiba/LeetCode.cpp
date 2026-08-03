#ifndef LEETCODE_PROBLEMS_LONGEST_WORD_IN_DICTIONARY_THROUGH_DELETING_H__
#define LEETCODE_PROBLEMS_LONGEST_WORD_IN_DICTIONARY_THROUGH_DELETING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_524 {

using Func = std::function<std::string(std::string, std::vector<std::string>&)>;

class LongestWordInDictionaryThroughDeletingSolution
    : public SolutionBase<Func> {
 public:
  LongestWordInDictionaryThroughDeletingSolution();

  std::string findLongestWord(std::string s,
                              std::vector<std::string>& dictionary);
};

}  // namespace problem_524
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LONGEST_WORD_IN_DICTIONARY_THROUGH_DELETING_H__
