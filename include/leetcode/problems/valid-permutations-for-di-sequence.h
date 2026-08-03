#ifndef LEETCODE_PROBLEMS_VALID_PERMUTATIONS_FOR_DI_SEQUENCE_H_
#define LEETCODE_PROBLEMS_VALID_PERMUTATIONS_FOR_DI_SEQUENCE_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_903 {

using Func = std::function<int(std::string)>;

class ValidPermutationsForDiSequenceSolution
    : public SolutionBase<Func> {
 public:
  ValidPermutationsForDiSequenceSolution();

  int numPermsDISequence(std::string s);
};

}  // namespace problem_903
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_PERMUTATIONS_FOR_DI_SEQUENCE_H_
