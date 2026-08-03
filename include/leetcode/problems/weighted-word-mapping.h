#ifndef LEETCODE_PROBLEMS_WEIGHTED_WORD_MAPPING_H_
#define LEETCODE_PROBLEMS_WEIGHTED_WORD_MAPPING_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3838 {

using Func = std::function<std::string(std::vector<std::string>&, std::vector<int>&)>;

class WeightedWordMappingSolution : public SolutionBase<Func> {
 public:
  WeightedWordMappingSolution();

  std::string mapWordWeights(std::vector<std::string>& words, std::vector<int>& weights);
};

}  // namespace problem_3838
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_WEIGHTED_WORD_MAPPING_H_
