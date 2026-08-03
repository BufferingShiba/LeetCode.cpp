#include "leetcode/core.h"

namespace leetcode {
namespace problem_79 {

using Func = std::function<bool(vector<vector<char>>&, string)>;

class WordSearchSolution : public SolutionBase<Func> {
 public:
  //! 79. Word Search
  //! https://leetcode.com/problems/word-search/
  bool exist(vector<vector<char>>& board, string word);

  WordSearchSolution();
};

}  // namespace problem_79
}  // namespace leetcode
