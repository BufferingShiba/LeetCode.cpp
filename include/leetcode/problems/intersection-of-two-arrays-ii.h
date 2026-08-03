#ifndef LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_ARRAYS_II_H__
#define LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_ARRAYS_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_350 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>;

class IntersectionOfTwoArraysIiSolution
    : public SolutionBase<Func> {
public:
    IntersectionOfTwoArraysIiSolution();

    std::vector<int> intersect(std::vector<int>& nums1,
                               std::vector<int>& nums2);
};

}  // namespace leetcode::problem_350

#endif  // LEETCODE_PROBLEMS_INTERSECTION_OF_TWO_ARRAYS_II_H__
