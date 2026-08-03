#ifndef LEETCODE_PROBLEMS_DECODE_XORED_ARRAY_H__
#define LEETCODE_PROBLEMS_DECODE_XORED_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1720 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class DecodeXoredArray : public SolutionBase<Func> {
public:
    DecodeXoredArray();
    std::vector<int> decode(std::vector<int>& encoded, int first);
};

using DecodeXoredArraySolution = DecodeXoredArray;

}  // namespace leetcode::problem_1720

#endif  // LEETCODE_PROBLEMS_DECODE_XORED_ARRAY_H__
