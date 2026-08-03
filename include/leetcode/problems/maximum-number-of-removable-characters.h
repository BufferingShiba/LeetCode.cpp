#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_REMOVABLE_CHARACTERS_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_REMOVABLE_CHARACTERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1898 {

using Func = std::function<int(std::string, std::string, std::vector<int>&)>;

class MaximumNumberOfRemovableCharactersSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfRemovableCharactersSolution();
  int maximumRemovals(std::string s, std::string p, std::vector<int>& removable);
};

}  // namespace problem_1898
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_REMOVABLE_CHARACTERS_H__
