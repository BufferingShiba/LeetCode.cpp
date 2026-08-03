#ifndef LEETCODE_PROBLEMS_X_OF_A_KIND_IN_A_DECK_OF_CARDS_H_
#define LEETCODE_PROBLEMS_X_OF_A_KIND_IN_A_DECK_OF_CARDS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_914 {

using Func = std::function<bool(std::vector<int>&)>;

class XOfAKindInADeckOfCardsSolution
    : public SolutionBase<Func> {
 public:
    XOfAKindInADeckOfCardsSolution();
    bool hasGroupsSizeX(std::vector<int>& deck);
};

}  // namespace leetcode::problem_914

#endif  // LEETCODE_PROBLEMS_X_OF_A_KIND_IN_A_DECK_OF_CARDS_H_
