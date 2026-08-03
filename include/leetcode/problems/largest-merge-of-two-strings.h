#ifndef LEETCODE_PROBLEMS_LARGEST_MERGE_OF_TWO_STRINGS_H__
#define LEETCODE_PROBLEMS_LARGEST_MERGE_OF_TWO_STRINGS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1754 {

using Func = std::function<std::string(std::string, std::string)>;

class LargestMergeOfTwoStringsSolution : public SolutionBase<Func> {
 public:
  std::string largestMerge(std::string word1, std::string word2);

  LargestMergeOfTwoStringsSolution();
};

}  // namespace problem_1754
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LARGEST_MERGE_OF_TWO_STRINGS_H__
