#ifndef LEETCODE_PROBLEMS_TOP_K_FREQUENT_WORDS_H_
#define LEETCODE_PROBLEMS_TOP_K_FREQUENT_WORDS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_692 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&, int)>;

class TopKFrequentWordsSolution : public SolutionBase<Func> {
 public:
  TopKFrequentWordsSolution();

  std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k);
};

}  // namespace problem_692
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TOP_K_FREQUENT_WORDS_H_
