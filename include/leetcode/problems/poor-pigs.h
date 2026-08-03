#ifndef LEETCODE_PROBLEMS_POOR_PIGS_H__
#define LEETCODE_PROBLEMS_POOR_PIGS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_458 {

using Func = std::function<int(int, int, int)>;

class PoorPigsSolution : public SolutionBase<Func> {
public:
    PoorPigsSolution();

    int poorPigs(int buckets, int minutesToDie, int minutesToTest);
};

}  // namespace leetcode::problem_458

#endif  // LEETCODE_PROBLEMS_POOR_PIGS_H__
