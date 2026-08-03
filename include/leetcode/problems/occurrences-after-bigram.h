#ifndef LEETCODE_PROBLEMS_OCCURRENCES_AFTER_BIGRAM_H_
#define LEETCODE_PROBLEMS_OCCURRENCES_AFTER_BIGRAM_H_

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1078 {

using Func = std::function<std::vector<std::string>(std::string, std::string, std::string)>;

class OccurrencesAfterBigramSolution : public SolutionBase<Func> {
 public:
  OccurrencesAfterBigramSolution();

  std::vector<std::string> findOcurrences(std::string text, std::string first, std::string second);
};

}  // namespace problem_1078
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_OCCURRENCES_AFTER_BIGRAM_H_
