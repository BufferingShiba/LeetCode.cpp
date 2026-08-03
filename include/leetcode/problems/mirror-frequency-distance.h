#ifndef LEETCODE_PROBLEMS_MIRROR_FREQUENCY_DISTANCE_H__
#define LEETCODE_PROBLEMS_MIRROR_FREQUENCY_DISTANCE_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_3889 {

using Func = std::function<int(std::string)>;

class MirrorFrequencyDistanceSolution : public SolutionBase<Func> {
public:
    MirrorFrequencyDistanceSolution();
    int mirrorFrequency(std::string s);
};

}  // namespace leetcode::problem_3889

#endif  // LEETCODE_PROBLEMS_MIRROR_FREQUENCY_DISTANCE_H__
