#ifndef LEETCODE_PROBLEMS_COUNT_PAIRS_OF_SIMILAR_STRINGS_H_
#define LEETCODE_PROBLEMS_COUNT_PAIRS_OF_SIMILAR_STRINGS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2506 {

using Func = std::function<int(std::vector<std::string>&)>;

class CountPairsOfSimilarStringsSolution : public SolutionBase<Func> {
 public:
  CountPairsOfSimilarStringsSolution();

  int similarPairs(std::vector<std::string>& words);
};

}  // namespace problem_2506
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_PAIRS_OF_SIMILAR_STRINGS_H_
