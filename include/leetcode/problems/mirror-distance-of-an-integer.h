#ifndef LEETCODE_PROBLEMS_MIRROR_DISTANCE_OF_AN_INTEGER_H__
#define LEETCODE_PROBLEMS_MIRROR_DISTANCE_OF_AN_INTEGER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3783 {

using Func = std::function<int(int)>;

class MirrorDistanceOfAnIntegerSolution : public SolutionBase<Func> {
public:
    MirrorDistanceOfAnIntegerSolution();

    int mirrorDistance(int n);
};

}  // namespace problem_3783
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MIRROR_DISTANCE_OF_AN_INTEGER_H__
