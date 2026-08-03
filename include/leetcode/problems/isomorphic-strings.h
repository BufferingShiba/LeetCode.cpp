#ifndef LEETCODE_PROBLEMS_ISOMORPHIC_STRINGS_H__
#define LEETCODE_PROBLEMS_ISOMORPHIC_STRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_205 {

using Func = std::function<bool(std::string, std::string)>;

class IsomorphicStringsSolution : public SolutionBase<Func> {
 public:
  IsomorphicStringsSolution();

  bool isIsomorphic(std::string s, std::string t);
};

}  // namespace problem_205
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ISOMORPHIC_STRINGS_H__
