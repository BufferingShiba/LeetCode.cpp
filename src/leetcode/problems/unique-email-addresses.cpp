#include "leetcode/problems/unique-email-addresses.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_929 {

namespace {

std::string normalize(const std::string& email) {
  const std::string::size_type at = email.find('@');
  std::string local = email.substr(0, at);
  const std::string domain = email.substr(at);

  std::string cleaned;
  cleaned.reserve(local.size());
  for (char c : local) {
    if (c == '+') break;
    if (c == '.') continue;
    cleaned.push_back(c);
  }
  return cleaned + domain;
}

int numUniqueEmailsImpl(std::vector<std::string>& emails) {
  std::unordered_set<std::string> seen;
  for (const auto& email : emails) {
    seen.insert(normalize(email));
  }
  return static_cast<int>(seen.size());
}

}  // namespace

UniqueEmailAddressesSolution::UniqueEmailAddressesSolution() {
  setMetaInfo({.id = 929,
               .title = "Unique Email Addresses",
               .url = "https://leetcode.com/problems/unique-email-addresses/"});
  registerStrategy({.name = "HashSetNormalize",
                    .expected = "Accepted",
                    .time_complexity = "O(n*L)",
                    .space_complexity = "O(n*L)",
                    .tags = {"Array", "Hash Table", "String"}},
                   numUniqueEmailsImpl);
}

int UniqueEmailAddressesSolution::numUniqueEmails(std::vector<std::string>& emails) {
  return getSolution()(emails);
}

}  // namespace problem_929
}  // namespace leetcode
