#include "leetcode/core.h"

namespace leetcode {
namespace problem_1239 {

using Func = std::function<int(vector<string>&)>;

class MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution : public SolutionBase<Func> {
 public:
  //! 1239. Maximum Length of a Concatenated String with Unique Characters
  //! https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
  int maxLength(vector<string>& arr);

  MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution();
};

}  // namespace problem_1239
}  // namespace leetcode
