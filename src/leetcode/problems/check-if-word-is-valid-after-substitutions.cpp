#include "leetcode/problems/check-if-word-is-valid-after-substitutions.h"

namespace leetcode {
namespace problem_1003 {

namespace {

bool isValidImpl(std::string s) {
  std::string st;
  for (char ch : s) {
    st.push_back(ch);
    int n = static_cast<int>(st.size());
    if (n >= 3 && st[n - 3] == 'a' && st[n - 2] == 'b' && st[n - 1] == 'c') {
      st.pop_back();
      st.pop_back();
      st.pop_back();
    }
  }
  return st.empty();
}

}  // namespace

CheckIfWordIsValidAfterSubstitutionsSolution::CheckIfWordIsValidAfterSubstitutionsSolution() {
  setMetaInfo({.id = 1003,
               .title = "Check If Word Is Valid After Substitutions",
               .url = "https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/"});
  registerStrategy({.name = "stack",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Stack"}},
                   isValidImpl);
  setDefaultStrategy();
}

bool CheckIfWordIsValidAfterSubstitutionsSolution::isValid(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1003
}  // namespace leetcode
