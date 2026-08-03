#ifndef LEETCODE_PROBLEMS_COUNT_ANAGRAMS_H__
#define LEETCODE_PROBLEMS_COUNT_ANAGRAMS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2514 {

class CountAnagramsSolution : public SolutionBase<std::function<int(std::string)>> {
 public:
  CountAnagramsSolution();

  int countAnagrams(std::string s);
};

}  // namespace problem_2514
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_ANAGRAMS_H__
