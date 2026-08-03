#include "leetcode/problems/find-the-sequence-of-strings-appeared-on-the-screen.h"

namespace leetcode::problem_3324 {

namespace {

std::vector<std::string> stringSequenceImpl(std::string target) {
  std::vector<std::string> result;
  std::string current;

  for (char goal : target) {
    // Key1: append 'a'
    current.push_back('a');
    result.push_back(current);

    // Key2: increment the last character until it matches goal
    while (current.back() != goal) {
      char& last = current.back();
      last = (last == 'z') ? 'a' : static_cast<char>(last + 1);
      result.push_back(current);
    }
  }

  return result;
}

}  // namespace

FindTheSequenceOfStringsAppearedOnTheScreenSolution::
    FindTheSequenceOfStringsAppearedOnTheScreenSolution() {
  setMetaInfo({.id = 3324,
               .title = "Find the Sequence of Strings Appeared on the Screen",
               .url = "https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(26 * n)",
       .space_complexity = "O(26 * n)",
       .tags = {"String", "Simulation"}},
      stringSequenceImpl);
}

std::vector<std::string>
FindTheSequenceOfStringsAppearedOnTheScreenSolution::stringSequence(
    std::string target) {
  return getSolution()(target);
}

}  // namespace leetcode::problem_3324
