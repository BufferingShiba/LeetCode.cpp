#include "leetcode/problems/strong-password-checker-ii.h"

#include <cctype>
#include <string>

namespace leetcode::problem_2299 {

namespace {

bool hasSpecial(char c) {
  const std::string specials = "!@#$%^&*()-+";
  return specials.find(c) != std::string::npos;
}

}  // namespace

bool strongPasswordCheckerIIImpl(const std::string& password) {
  if (password.size() < 8) {
    return false;
  }

  bool hasLower = false;
  bool hasUpper = false;
  bool hasDigit = false;
  bool hasSpecialChar = false;

  for (std::size_t i = 0; i < password.size(); ++i) {
    char c = password[i];
    if (i > 0 && c == password[i - 1]) {
      return false;
    }
    if (std::islower(static_cast<unsigned char>(c))) {
      hasLower = true;
    } else if (std::isupper(static_cast<unsigned char>(c))) {
      hasUpper = true;
    } else if (std::isdigit(static_cast<unsigned char>(c))) {
      hasDigit = true;
    } else if (hasSpecial(c)) {
      hasSpecialChar = true;
    }
  }

  return hasLower && hasUpper && hasDigit && hasSpecialChar;
}

StrongPasswordCheckerIiSolution::StrongPasswordCheckerIiSolution() {
  this->setMetaInfo({.id = 2299,
                     .title = "Strong Password Checker II",
                     .url = "https://leetcode.com/problems/strong-password-checker-ii/"});
  this->registerStrategy(
      {"single-pass-scan", "Accepted", "O(n)", "O(1)", {"String"}},
      strongPasswordCheckerIIImpl);
}

bool StrongPasswordCheckerIiSolution::strongPasswordCheckerII(
    std::string password) {
  return this->getSolution()(password);
}

}  // namespace leetcode::problem_2299
