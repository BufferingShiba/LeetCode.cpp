#ifndef LEETCODE_GROUP_ANAGRAMS_H__
#define LEETCODE_GROUP_ANAGRAMS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_49 {

using Func = std::function<std::vector<std::vector<std::string>>(std::vector<std::string>&)>;

class GroupAnagramsSolution : public SolutionBase<Func> {
 public:
  GroupAnagramsSolution();

  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
};

}  // namespace problem_49
}  // namespace leetcode

#endif  // LEETCODE_GROUP_ANAGRAMS_H__
