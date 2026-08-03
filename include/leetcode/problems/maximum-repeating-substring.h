#ifndef LEETCODE_PROBLEMS_MAXIMUM_REPEATING_SUBSTRING_H__
#define LEETCODE_PROBLEMS_MAXIMUM_REPEATING_SUBSTRING_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1668 {

using Func = std::function<int(std::string, std::string)>;

class MaximumRepeatingSubstringSolution : public SolutionBase<Func> {
 public:
  MaximumRepeatingSubstringSolution();

  int maxRepeating(std::string sequence, std::string word);
};

}  // namespace problem_1668
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_REPEATING_SUBSTRING_H__
