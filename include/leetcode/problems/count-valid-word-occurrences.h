#ifndef LEETCODE_PROBLEMS_COUNT_VALID_WORD_OCCURRENCES_H_
#define LEETCODE_PROBLEMS_COUNT_VALID_WORD_OCCURRENCES_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3926 {

using Func = std::function<std::vector<int>(std::vector<std::string>&, std::vector<std::string>&)>;

class CountValidWordOccurrencesSolution : public SolutionBase<Func> {
 public:
  CountValidWordOccurrencesSolution();

  std::vector<int> countWordOccurrences(std::vector<std::string>& chunks,
                                         std::vector<std::string>& queries);
};

}  // namespace problem_3926
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_VALID_WORD_OCCURRENCES_H_
