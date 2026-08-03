#ifndef LEETCODE_PROBLEMS_MINIMUM_DELETIONS_TO_MAKE_ARRAY_BEAUTIFUL_H__
#define LEETCODE_PROBLEMS_MINIMUM_DELETIONS_TO_MAKE_ARRAY_BEAUTIFUL_H__

#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2216 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumDeletionsToMakeArrayBeautifulSolution
    : public SolutionBase<Func> {
public:
    MinimumDeletionsToMakeArrayBeautifulSolution();

    int minDeletion(std::vector<int>& nums);
};

}  // namespace problem_2216
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DELETIONS_TO_MAKE_ARRAY_BEAUTIFUL_H__
