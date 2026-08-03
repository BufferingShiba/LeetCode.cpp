#include "leetcode/problems/lemonade-change.h"

namespace leetcode::problem_860 {

bool lemonadeChangeImpl(std::vector<int>& bills) {
  int five = 0;
  int ten = 0;
  for (int bill : bills) {
    if (bill == 5) {
      ++five;
    } else if (bill == 10) {
      if (five == 0) {
        return false;
      }
      --five;
      ++ten;
    } else {  // bill == 20
      if (ten > 0 && five > 0) {
        --ten;
        --five;
      } else if (five >= 3) {
        five -= 3;
      } else {
        return false;
      }
    }
  }
  return true;
}

LemonadeChangeSolution::LemonadeChangeSolution() {
  setMetaInfo({.id = 860,
               .title = "Lemonade Change",
               .url = "https://leetcode.com/problems/lemonade-change/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      lemonadeChangeImpl);
}

bool LemonadeChangeSolution::lemonadeChange(std::vector<int>& bills) {
  return getSolution()(bills);
}

}  // namespace leetcode::problem_860
