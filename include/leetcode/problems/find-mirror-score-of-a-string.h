#include "leetcode/core.h"

namespace leetcode {
namespace problem_3412 {

using Func = std::function<long(string)>;

class FindMirrorScoreOfAStringSolution : public SolutionBase<Func> {
 public:
  //! 3412. Find Mirror Score of a String
  //! https://leetcode.com/problems/find-mirror-score-of-a-string/
  long calculateScore(string s);

  FindMirrorScoreOfAStringSolution();
};

}  // namespace problem_3412
}  // namespace leetcode
