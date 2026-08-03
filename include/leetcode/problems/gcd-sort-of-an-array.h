#ifndef LEETCODE_PROBLEMS_GCD_SORT_OF_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_GCD_SORT_OF_AN_ARRAY_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1998 {

using Func = std::function<bool(std::vector<int>&)>;

class GcdSortOfAnArraySolution : public SolutionBase<Func> {
public:
    GcdSortOfAnArraySolution();
    bool gcdSort(std::vector<int>& nums);
};

}  // namespace problem_1998
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GCD_SORT_OF_AN_ARRAY_H__
