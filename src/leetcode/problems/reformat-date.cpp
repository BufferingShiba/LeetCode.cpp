#include "leetcode/problems/reformat-date.h"

#include <sstream>
#include <unordered_map>

namespace leetcode::problem_1507 {

namespace {

std::string reformatDateImpl(std::string date) {
  static const std::unordered_map<std::string, std::string> month = {
      {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
      {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
      {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

  std::istringstream iss(date);
  std::string day, mon, year;
  iss >> day >> mon >> year;

  // Day: strip the last two characters (ordinal suffix "st"/"nd"/"rd"/"th").
  std::string dayNum = day.substr(0, day.size() - 2);
  if (dayNum.size() == 1) {
    dayNum = "0" + dayNum;
  }

  return year + "-" + month.at(mon) + "-" + dayNum;
}

}  // namespace

ReformatDateSolution::ReformatDateSolution() {
  setMetaInfo({.id = 1507,
               .title = "Reformat Date",
               .url = "https://leetcode.com/problems/reformat-date/"});
  registerStrategy(
      {.name = "string-parsing",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"String"}},
      reformatDateImpl);
}

std::string ReformatDateSolution::reformatDate(std::string date) {
  return getSolution()(date);
}

}  // namespace leetcode::problem_1507
