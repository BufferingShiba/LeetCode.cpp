#include "leetcode/problems/reward-top-k-students.h"

#include <algorithm>
#include <sstream>
#include <unordered_set>

namespace leetcode {
namespace problem_2512 {

namespace {

std::vector<int> topStudentsImpl(std::vector<std::string>& positive_feedback,
                                 std::vector<std::string>& negative_feedback,
                                 std::vector<std::string>& report,
                                 std::vector<int>& student_id, int k) {
  // Build hash sets for O(1) word lookup.
  std::unordered_set<std::string> pos_set(positive_feedback.begin(),
                                           positive_feedback.end());
  std::unordered_set<std::string> neg_set(negative_feedback.begin(),
                                           negative_feedback.end());

  const int n = static_cast<int>(report.size());
  // Pair of (points, student_id); we'll negate points for easy sorting.
  std::vector<std::pair<int, int>> students;
  students.reserve(n);

  for (int i = 0; i < n; ++i) {
    int points = 0;
    std::istringstream iss(report[i]);
    std::string word;
    while (iss >> word) {
      if (pos_set.count(word)) {
        points += 3;
      } else if (neg_set.count(word)) {
        points -= 1;
      }
    }
    // Store (-points, id) so that sorting ascending gives descending points
    // and ascending id on tie.
    students.emplace_back(-points, student_id[i]);
  }

  // Partial sort to get top k: nth_element + sort the first k.
  // Or just sort all and take first k — n <= 1e4, simple is fine.
  std::sort(students.begin(), students.end());

  std::vector<int> result;
  result.reserve(k);
  for (int i = 0; i < k; ++i) {
    result.push_back(students[i].second);
  }
  return result;
}

}  // namespace

RewardTopKStudentsSolution::RewardTopKStudentsSolution() {
  setMetaInfo({.id = 2512,
               .title = "Reward Top K Students",
               .url = "https://leetcode.com/problems/reward-top-k-students/"});

  registerStrategy(
      {.name = "HashSet + Sorting",
       .expected = "Accepted",
       .time_complexity = "O((P+N) + n*L + n log n)",
       .space_complexity = "O(P+N + n)",
       .tags = {"Array", "Hash Table", "String", "Sorting"}},
      topStudentsImpl);
}

std::vector<int> RewardTopKStudentsSolution::topStudents(
    std::vector<std::string>& positive_feedback,
    std::vector<std::string>& negative_feedback,
    std::vector<std::string>& report,
    std::vector<int>& student_id, int k) {
  return getSolution()(positive_feedback, negative_feedback, report,
                       student_id, k);
}

}  // namespace problem_2512
}  // namespace leetcode
