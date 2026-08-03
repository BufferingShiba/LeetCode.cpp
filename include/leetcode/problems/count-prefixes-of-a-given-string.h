#ifndef LEETCODE_PROBLEMS_COUNT_PREFIXES_OF_A_GIVEN_STRING_H_
#define LEETCODE_PROBLEMS_COUNT_PREFIXES_OF_A_GIVEN_STRING_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2255 {

using Func = std::function<int(std::vector<std::string>&, std::string)>;

class CountPrefixesOfAGivenString : public SolutionBase<Func> {
 public:
  int countPrefixes(std::vector<std::string>& words, std::string s);

  CountPrefixesOfAGivenString();
};

}  // namespace problem_2255
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_PREFIXES_OF_A_GIVEN_STRING_H_
