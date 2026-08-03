#ifndef LEETCODE_PROBLEMS_COUNT_PREFIX_AND_SUFFIX_PAIRS_I_H__
#define LEETCODE_PROBLEMS_COUNT_PREFIX_AND_SUFFIX_PAIRS_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3042 {

using Func = std::function<int(std::vector<std::string>&)>;

class CountPrefixAndSuffixPairsISolution : public SolutionBase<Func> {
 public:
  CountPrefixAndSuffixPairsISolution();

  int countPrefixSuffixPairs(std::vector<std::string>& words);
};

}  // namespace problem_3042
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_PREFIX_AND_SUFFIX_PAIRS_I_H__
