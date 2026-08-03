#ifndef LEETCODE_PROBLEMS_SLOWEST_KEY_H__
#define LEETCODE_PROBLEMS_SLOWEST_KEY_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1629 {

using Func = std::function<char(std::vector<int>&, std::string)>;

class SlowestKeySolution : public SolutionBase<Func> {
 public:
  SlowestKeySolution();

  char slowestKey(std::vector<int>& releaseTimes, std::string keysPressed);
};

}  // namespace problem_1629
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SLOWEST_KEY_H__
