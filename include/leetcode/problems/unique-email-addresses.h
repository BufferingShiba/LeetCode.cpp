#ifndef LEETCODE_PROBLEMS_UNIQUE_EMAIL_ADDRESSES_H__
#define LEETCODE_PROBLEMS_UNIQUE_EMAIL_ADDRESSES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_929 {

using Func = std::function<int(std::vector<std::string>&)>;

class UniqueEmailAddressesSolution : public SolutionBase<Func> {
 public:
  UniqueEmailAddressesSolution();

  int numUniqueEmails(std::vector<std::string>& emails);
};

}  // namespace problem_929
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNIQUE_EMAIL_ADDRESSES_H__
