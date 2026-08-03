#ifndef LEETCODE_PROBLEMS_FIND_THE_SUM_OF_ENCRYPTED_INTEGERS_H__
#define LEETCODE_PROBLEMS_FIND_THE_SUM_OF_ENCRYPTED_INTEGERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3079 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheSumOfEncryptedIntegersSolution : public SolutionBase<Func> {
 public:
  FindTheSumOfEncryptedIntegersSolution();

  int sumOfEncryptedInt(std::vector<int>& nums);
};

}  // namespace problem_3079
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_SUM_OF_ENCRYPTED_INTEGERS_H__
