#ifndef LEETCODE_PROBLEMS_COUNT_ASTERISKS_H_
#define LEETCODE_PROBLEMS_COUNT_ASTERISKS_H_

#include <string>
#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2315 {

using Func = std::function<int(std::string)>;

class CountAsterisksSolution : public SolutionBase<Func> {
 public:
  CountAsterisksSolution();

  int countAsterisks(std::string s);
};

}  // namespace problem_2315
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_ASTERISKS_H_
