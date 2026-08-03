#ifndef LEETCODE_PROBLEM_2266_H_
#define LEETCODE_PROBLEM_2266_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2266 {

using Func = std::function<int(const std::string&)>;

class CountNumberOfTextsSolution : public SolutionBase<Func> {
 public:
  CountNumberOfTextsSolution();

  int countTexts(std::string pressedKeys);
};

}  // namespace problem_2266
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2266_H_
