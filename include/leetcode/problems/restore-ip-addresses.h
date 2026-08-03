#include "leetcode/core.h"

namespace leetcode {
namespace problem_93 {

using Func = std::function<vector<string>(string)>;

class RestoreIpAddressesSolution : public SolutionBase<Func> {
 public:
  //! 93. Restore IP Addresses
  //! https://leetcode.com/problems/restore-ip-addresses/
  vector<string> restoreIpAddresses(string s);

  RestoreIpAddressesSolution();
};

}  // namespace problem_93
}  // namespace leetcode
