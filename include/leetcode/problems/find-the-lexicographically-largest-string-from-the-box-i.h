#ifndef LEETCODE_PROBLEMS_FIND_THE_LEXICOGRAPHICALLY_LARGEST_STRING_FROM_THE_BOX_I_H_
#define LEETCODE_PROBLEMS_FIND_THE_LEXICOGRAPHICALLY_LARGEST_STRING_FROM_THE_BOX_I_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3403 {

using Func = std::function<std::string(std::string, int)>;

class FindTheLexicographicallyLargestStringFromTheBoxISolution
    : public SolutionBase<Func> {
 public:
  FindTheLexicographicallyLargestStringFromTheBoxISolution();

  std::string answerString(std::string word, int numFriends);
};

}  // namespace problem_3403
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_LEXICOGRAPHICALLY_LARGEST_STRING_FROM_THE_BOX_I_H_
