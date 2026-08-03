#ifndef LEETCODE_PROBLEMS_UNIQUE_NUMBER_OF_OCCURRENCES_H_
#define LEETCODE_PROBLEMS_UNIQUE_NUMBER_OF_OCCURRENCES_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {

using UniqueNumberOfOccurrencesSignature = std::function<bool(std::vector<int>&)>;

class UniqueNumberOfOccurrencesSolution
    : public SolutionBase<UniqueNumberOfOccurrencesSignature> {
 public:
  bool uniqueOccurrences(std::vector<int>& arr);

  UniqueNumberOfOccurrencesSolution();
};

}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNIQUE_NUMBER_OF_OCCURRENCES_H_
