#ifndef LEETCODE_PROBLEMS_REMOVE_ADJACENT_ALMOST_EQUAL_CHARACTERS_H__
#define LEETCODE_PROBLEMS_REMOVE_ADJACENT_ALMOST_EQUAL_CHARACTERS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_2957 {

using Func = std::function<int(std::string)>;

class RemoveAdjacentAlmostEqualCharactersSolution
    : public SolutionBase<Func> {
 public:
  RemoveAdjacentAlmostEqualCharactersSolution();

  int removeAlmostEqualCharacters(std::string word) {
    return getSolution()(std::move(word));
  }
};

}  // namespace problem_2957
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_ADJACENT_ALMOST_EQUAL_CHARACTERS_H__
