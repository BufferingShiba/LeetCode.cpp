#ifndef LEETCODE_PROBLEMS_MINIMUM_DELETIONS_TO_MAKE_CHARACTER_FREQUENCIES_UNIQUE_H__
#define LEETCODE_PROBLEMS_MINIMUM_DELETIONS_TO_MAKE_CHARACTER_FREQUENCIES_UNIQUE_H__

#include <string>
#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1647 {

using Func = std::function<int(std::string)>;

class MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution
    : public SolutionBase<Func> {
 public:
  MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution();

  int minDeletions(std::string s);
};

}  // namespace problem_1647
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DELETIONS_TO_MAKE_CHARACTER_FREQUENCIES_UNIQUE_H__
