#ifndef LEETCODE_PROBLEM_2947_H_
#define LEETCODE_PROBLEM_2947_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2947 {

using Func = std::function<int(std::string, int)>;

class CountBeautifulSubstringsISolution : public SolutionBase<Func> {
 public:
  CountBeautifulSubstringsISolution();

  int beautifulSubstrings(std::string s, int k);
};

}  // namespace problem_2947
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2947_H_
