#ifndef LEETCODE_PROBLEMS_SHORT_ENCODING_OF_WORDS_H_
#define LEETCODE_PROBLEMS_SHORT_ENCODING_OF_WORDS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_820 {

using Func = std::function<int(std::vector<std::string>&)>;

class ShortEncodingOfWordsSolution : public SolutionBase<Func> {
 public:
  ShortEncodingOfWordsSolution();

  int minimumLengthEncoding(std::vector<std::string>& words);
};

}  // namespace problem_820
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORT_ENCODING_OF_WORDS_H_
