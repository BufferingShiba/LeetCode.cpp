#ifndef LEETCODE_PROBLEMS_TWO_LETTER_CARD_GAME_H__
#define LEETCODE_PROBLEMS_TWO_LETTER_CARD_GAME_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3664 {

using Func = std::function<int(std::vector<std::string>&, char)>;

class TwoLetterCardGameSolution : public SolutionBase<Func> {
 public:
  int score(std::vector<std::string>& cards, char x);

  TwoLetterCardGameSolution();
};

}  // namespace leetcode::problem_3664

#endif
