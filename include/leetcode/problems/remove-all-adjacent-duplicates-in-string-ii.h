#ifndef LEETCODE_PROBLEMS_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_II_H_
#define LEETCODE_PROBLEMS_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_II_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1209 {

using Func = std::function<std::string(std::string, int)>;

class RemoveAllAdjacentDuplicatesInStringIiSolution
    : public SolutionBase<Func> {
public:
    RemoveAllAdjacentDuplicatesInStringIiSolution();
    std::string removeDuplicates(std::string s, int k);
};

}  // namespace problem_1209
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_ALL_ADJACENT_DUPLICATES_IN_STRING_II_H_
