#ifndef LEETCODE_PROBLEMS_SENTENCE_SIMILARITY_III_H_
#define LEETCODE_PROBLEMS_SENTENCE_SIMILARITY_III_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1813 {

using Func = std::function<bool(std::string, std::string)>;

class SentenceSimilarityIiiSolution : public SolutionBase<Func> {
 public:
  SentenceSimilarityIiiSolution();

  bool areSentencesSimilar(std::string sentence1, std::string sentence2);
};

}  // namespace problem_1813
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SENTENCE_SIMILARITY_III_H_
