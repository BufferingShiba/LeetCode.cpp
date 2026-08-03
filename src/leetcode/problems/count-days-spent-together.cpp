#include "leetcode/problems/count-days-spent-together.h"

namespace leetcode {
namespace problem_2409 {

namespace {

int toDay(const std::string& date) {
  static const int daysPerMonth[12] = {31, 28, 31, 30, 31, 30,
                                       31, 31, 30, 31, 30, 31};
  int month = (date[0] - '0') * 10 + (date[1] - '0');
  int day = (date[3] - '0') * 10 + (date[4] - '0');
  int total = 0;
  for (int m = 0; m < month - 1; ++m) {
    total += daysPerMonth[m];
  }
  return total + day;
}

int countDaysTogetherImpl(std::string arriveAlice, std::string leaveAlice,
                          std::string arriveBob, std::string leaveBob) {
  int aStart = toDay(arriveAlice), aEnd = toDay(leaveAlice);
  int bStart = toDay(arriveBob), bEnd = toDay(leaveBob);
  int start = std::max(aStart, bStart);
  int end = std::min(aEnd, bEnd);
  return end >= start ? end - start + 1 : 0;
}

}  // namespace

CountDaysSpentTogetherSolution::CountDaysSpentTogetherSolution() {
  setMetaInfo({2409, "Count Days Spent Together",
               "https://leetcode.com/problems/count-days-spent-together/"});
  registerStrategy(
      {"interval intersection", "Accepted", "O(1)", "O(1)",
       {"Math", "String"}},
      countDaysTogetherImpl);
}

int CountDaysSpentTogetherSolution::countDaysTogether(
    std::string arriveAlice, std::string leaveAlice, std::string arriveBob,
    std::string leaveBob) {
  return getSolution()(arriveAlice, leaveAlice, arriveBob, leaveBob);
}

}  // namespace problem_2409
}  // namespace leetcode
