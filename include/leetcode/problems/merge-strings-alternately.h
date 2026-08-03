#ifndef LEETCODE_PROBLEMS_MERGE_STRINGS_ALTERNATELY_H__
#define LEETCODE_PROBLEMS_MERGE_STRINGS_ALTERNATELY_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1768 {

using Func = std::function<std::string(std::string, std::string)>;

class MergeStringsAlternatelySolution
    : public SolutionBase<Func> {
 public:
  MergeStringsAlternatelySolution();

  std::string mergeAlternately(std::string word1, std::string word2);
};

}  // namespace problem_1768
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MERGE_STRINGS_ALTERNATELY_H__
