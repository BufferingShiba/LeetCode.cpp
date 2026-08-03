#ifndef LEETCODE_PROBLEMS_VALID_ANAGRAM_H__
#define LEETCODE_PROBLEMS_VALID_ANAGRAM_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_242 {

using Func = std::function<bool(std::string, std::string)>;

class ValidAnagramSolution : public SolutionBase<Func> {
 public:
  ValidAnagramSolution();

  bool isAnagram(std::string s, std::string t);
};

}  // namespace problem_242
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_ANAGRAM_H__
