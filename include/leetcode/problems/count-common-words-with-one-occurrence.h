#ifndef LEETCODE_PROBLEMS_COUNT_COMMON_WORDS_WITH_ONE_OCCURRENCE_H__
#define LEETCODE_PROBLEMS_COUNT_COMMON_WORDS_WITH_ONE_OCCURRENCE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2085 {

using Func = std::function<int(std::vector<std::string>&, std::vector<std::string>&)>;

class CountCommonWordsWithOneOccurrenceSolution
    : public SolutionBase<Func> {
 public:
  CountCommonWordsWithOneOccurrenceSolution();

  int countWords(std::vector<std::string>& words1,
                 std::vector<std::string>& words2);
};

}  // namespace problem_2085
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_COMMON_WORDS_WITH_ONE_OCCURRENCE_H__
