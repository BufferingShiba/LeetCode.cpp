#ifndef LEETCODE_PROBLEM_808_SOUP_SERVINGS_H
#define LEETCODE_PROBLEM_808_SOUP_SERVINGS_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_808 {

using Func = std::function<double(int)>;

class SoupServingsSolution : public SolutionBase<Func> {
 public:
  SoupServingsSolution();

  double soupServings(int n);
};

}  // namespace problem_808
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_808_SOUP_SERVINGS_H
