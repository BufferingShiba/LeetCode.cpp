#ifndef LEETCODE_PROBLEMS_ALICE_AND_BOB_PLAYING_FLOWER_GAME_H_
#define LEETCODE_PROBLEMS_ALICE_AND_BOB_PLAYING_FLOWER_GAME_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3021 {

using Func = std::function<long long(int, int)>;

class AliceAndBobPlayingFlowerGameSolution : public SolutionBase<Func> {
 public:
  AliceAndBobPlayingFlowerGameSolution();

  long long flowerGame(int n, int m);
};

}  // namespace problem_3021
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ALICE_AND_BOB_PLAYING_FLOWER_GAME_H_
