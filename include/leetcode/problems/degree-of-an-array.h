#ifndef LEETCODE_PROBLEMS_DEGREE_OF_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_DEGREE_OF_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_697 {

using Func = std::function<int(std::vector<int>&)>;

class DegreeOfAnArraySolution : public SolutionBase<Func> {
public:
    DegreeOfAnArraySolution();

    int findShortestSubArray(std::vector<int>& nums);
};

}  // namespace problem_697
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DEGREE_OF_AN_ARRAY_H__
