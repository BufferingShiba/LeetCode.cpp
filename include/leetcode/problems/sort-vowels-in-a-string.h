#include "leetcode/core.h"

namespace leetcode {
namespace problem_2785 {

using Func = std::function<string(string)>;

class SortVowelsInAStringSolution : public SolutionBase<Func> {
 public:
  //! 2785. Sort Vowels in a String
  //! https://leetcode.com/problems/sort-vowels-in-a-string/
  string sortVowels(string s);

  SortVowelsInAStringSolution();
};

}  // namespace problem_2785
}  // namespace leetcode
