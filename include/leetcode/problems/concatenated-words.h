#ifndef LEETCODE_PROBLEMS_CONCATENATED_WORDS_H__
#define LEETCODE_PROBLEMS_CONCATENATED_WORDS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_472 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class ConcatenatedWordsSolution : public SolutionBase<Func> {
 public:
  ConcatenatedWordsSolution();

  std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words);
};

}  // namespace problem_472
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONCATENATED_WORDS_H__
