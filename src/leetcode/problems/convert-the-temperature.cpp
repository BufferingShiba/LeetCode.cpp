#include "leetcode/problems/convert-the-temperature.h"

namespace leetcode::problem_2469 {

namespace {

std::vector<double> convertTemperatureImpl(double celsius) {
  return {celsius + 273.15, celsius * 1.80 + 32.00};
}

}  // namespace

ConvertTheTemperatureSolution::ConvertTheTemperatureSolution() {
  setMetaInfo({.id = 2469,
               .title = "Convert the Temperature",
               .url =
                   "https://leetcode.com/problems/convert-the-temperature/"});
  registerStrategy(
      {.name = "direct_formula",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      convertTemperatureImpl);
}

std::vector<double> ConvertTheTemperatureSolution::convertTemperature(
    double celsius) {
  return getSolution()(celsius);
}

}  // namespace leetcode::problem_2469
