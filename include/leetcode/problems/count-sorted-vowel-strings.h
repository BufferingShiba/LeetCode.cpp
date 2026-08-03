#ifndef LEETCODE_PROBLEMS_COUNT_SORTED_VOWEL_STRINGS_H_
#define LEETCODE_PROBLEMS_COUNT_SORTED_VOWEL_STRINGS_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1641 {

using Func = std::function<int(int)>;

class CountSortedVowelStringsSolution
    : public SolutionBase<Func> {
 public:
  CountSortedVowelStringsSolution();

  int countVowelStrings(int n);
};

}  // namespace problem_1641
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SORTED_VOWEL_STRINGS_H_
