#pragma once

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_3704 {

using Func = std::function<long long(long long)>;

class CountNoZeroPairsSolution : public SolutionBase<Func> {
public:
    CountNoZeroPairsSolution();

    long long countNoZeroPairs(long long n);
};

}  // namespace problem_3704
}  // namespace leetcode
