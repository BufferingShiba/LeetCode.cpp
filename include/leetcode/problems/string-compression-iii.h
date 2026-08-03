#ifndef LEETCODE_PROBLEMS_STRING_COMPRESSION_III_H__
#define LEETCODE_PROBLEMS_STRING_COMPRESSION_III_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3163 {

using Func = std::function<std::string(std::string)>;

class StringCompressionIiiSolution : public SolutionBase<Func> {
public:
    StringCompressionIiiSolution();
    std::string compressedString(std::string word);
};

}  // namespace problem_3163
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_STRING_COMPRESSION_III_H__
