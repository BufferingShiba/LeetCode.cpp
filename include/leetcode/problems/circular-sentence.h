#ifndef LEETCODE_PROBLEMS_CIRCULAR_SENTENCE_H__
#define LEETCODE_PROBLEMS_CIRCULAR_SENTENCE_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2490 {

using Func = std::function<bool(std::string)>;

class CircularSentenceSolution : public SolutionBase<Func> {
 public:
  CircularSentenceSolution();

  bool isCircularSentence(std::string sentence);
};

}  // namespace problem_2490
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CIRCULAR_SENTENCE_H__
