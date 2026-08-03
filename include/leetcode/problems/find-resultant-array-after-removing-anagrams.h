#ifndef LEETCODE_PROBLEMS_FIND_RESULTANT_ARRAY_AFTER_REMOVING_ANAGRAMS_H__
#define LEETCODE_PROBLEMS_FIND_RESULTANT_ARRAY_AFTER_REMOVING_ANAGRAMS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2273 {

using Func = std::function<std::vector<std::string>(std::vector<std::string>&)>;

class FindResultantArrayAfterRemovingAnagramsSolution
    : public SolutionBase<Func> {
 public:
  FindResultantArrayAfterRemovingAnagramsSolution();

  std::vector<std::string> removeAnagrams(std::vector<std::string>& words);
};

}  // namespace problem_2273
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_RESULTANT_ARRAY_AFTER_REMOVING_ANAGRAMS_H__
