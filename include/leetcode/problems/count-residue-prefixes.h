#ifndef LEETCODE_PROBLEMS_COUNT_RESIDUE_PREFIXES_H_
#define LEETCODE_PROBLEMS_COUNT_RESIDUE_PREFIXES_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3803 {

using Func = std::function<int(std::string)>;

class CountResiduePrefixesSolution : public SolutionBase<Func> {
 public:
  CountResiduePrefixesSolution();

  int residuePrefixes(std::string s);
};

}  // namespace problem_3803
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_RESIDUE_PREFIXES_H_
