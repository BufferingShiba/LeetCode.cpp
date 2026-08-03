#ifndef LEETCODE_PROBLEMS_RANSOM_NOTE_H__
#define LEETCODE_PROBLEMS_RANSOM_NOTE_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_383 {

using Func = std::function<bool(std::string, std::string)>;

class RansomNoteSolution : public SolutionBase<Func> {
public:
    RansomNoteSolution();

    bool canConstruct(std::string ransomNote, std::string magazine);
};

}  // namespace leetcode::problem_383

#endif  // LEETCODE_PROBLEMS_RANSOM_NOTE_H__
