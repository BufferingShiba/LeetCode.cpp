#ifndef LEETCODE_PROBLEMS_FAIR_DISTRIBUTION_OF_COOKIES_H__
#define LEETCODE_PROBLEMS_FAIR_DISTRIBUTION_OF_COOKIES_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2305 {

using Func = std::function<int(std::vector<int>&, int)>;

class FairDistributionOfCookiesSolution : public SolutionBase<Func> {
 public:
  FairDistributionOfCookiesSolution();

  int distributeCookies(std::vector<int>& cookies, int k);
};

}  // namespace problem_2305
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FAIR_DISTRIBUTION_OF_COOKIES_H__
