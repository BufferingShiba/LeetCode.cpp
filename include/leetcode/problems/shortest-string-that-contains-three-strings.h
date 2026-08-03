#ifndef LEETCODE_PROBLEMS_SHORTEST_STRING_THAT_CONTAINS_THREE_STRINGS_H_
#define LEETCODE_PROBLEMS_SHORTEST_STRING_THAT_CONTAINS_THREE_STRINGS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_2800 {

using ShortestStringThatContainsThreeStringsFunc =
    std::function<std::string(std::string, std::string, std::string)>;

class ShortestStringThatContainsThreeStringsSolution
    : public SolutionBase<ShortestStringThatContainsThreeStringsFunc> {
 public:
  ShortestStringThatContainsThreeStringsSolution();

  std::string minimumString(std::string a, std::string b, std::string c);
};

}  // namespace problem_2800
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SHORTEST_STRING_THAT_CONTAINS_THREE_STRINGS_H_
