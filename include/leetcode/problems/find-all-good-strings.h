#ifndef LEETCODE_PROBLEMS_FIND_ALL_GOOD_STRINGS_H_
#define LEETCODE_PROBLEMS_FIND_ALL_GOOD_STRINGS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1397 {

using Func = std::function<int(int, std::string, std::string, std::string)>;

class FindAllGoodStringsSolution : public SolutionBase<Func> {
public:
    FindAllGoodStringsSolution();
};

}  // namespace problem_1397
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_ALL_GOOD_STRINGS_H_
