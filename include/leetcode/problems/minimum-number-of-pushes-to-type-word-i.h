#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_PUSHES_TO_TYPE_WORD_I_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_PUSHES_TO_TYPE_WORD_I_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3014 {

using Func = std::function<int(std::string)>;

class MinimumNumberOfPushesToTypeWordISolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfPushesToTypeWordISolution();

  int minimumPushes(std::string word);
};

}  // namespace problem_3014
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_PUSHES_TO_TYPE_WORD_I_H_
