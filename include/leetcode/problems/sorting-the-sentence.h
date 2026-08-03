#ifndef LEETCODE_PROBLEMS_SORTING_THE_SENTENCE_H_
#define LEETCODE_PROBLEMS_SORTING_THE_SENTENCE_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1859 {

using Func = std::function<std::string(std::string)>;

class SortingTheSentenceSolution : public SolutionBase<Func> {
 public:
  SortingTheSentenceSolution();

  std::string sortSentence(std::string s);
};

}  // namespace problem_1859
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SORTING_THE_SENTENCE_H_
