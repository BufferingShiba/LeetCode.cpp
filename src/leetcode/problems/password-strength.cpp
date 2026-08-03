#include "leetcode/problems/password-strength.h"

#include <set>

namespace leetcode {
namespace problem_3941 {

static int solution1(string password) {
  std::set<char> lower, upper, digit, special;
  for (char c : password) {
    if (c >= 'a' && c <= 'z') {
      lower.insert(c);
    } else if (c >= 'A' && c <= 'Z') {
      upper.insert(c);
    } else if (c >= '0' && c <= '9') {
      digit.insert(c);
    } else {
      special.insert(c);  // only '!', '@', '#', '$' are present
    }
  }
  return static_cast<int>(lower.size() * 1 + upper.size() * 2 +
                          digit.size() * 3 + special.size() * 5);
}

PasswordStrengthSolution::PasswordStrengthSolution() {
  setMetaInfo({
      .id = 3941,
      .title = "Password Strength",
      .url = "https://leetcode.com/problems/password-strength"
  });
  registerStrategy({.name = "Count Distinct Characters"}, solution1);
}

int PasswordStrengthSolution::passwordStrength(string password) {
  return getSolution()(password);
}

}  // namespace problem_3941
}  // namespace leetcode
