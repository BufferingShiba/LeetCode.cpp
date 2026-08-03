#include "leetcode/problems/course-schedule-iii.h"

#include <algorithm>
#include <queue>
#include <vector>

namespace leetcode::problem_630 {

static int scheduleCourseImpl(std::vector<std::vector<int>>& courses) {
  // Sort by lastDay ascending
  std::sort(courses.begin(), courses.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[1] < b[1];
            });

  std::priority_queue<int> maxHeap;  // max-heap of durations
  int totalTime = 0;

  for (const auto& course : courses) {
    int duration = course[0];
    int lastDay = course[1];

    totalTime += duration;
    maxHeap.push(duration);

    if (totalTime > lastDay) {
      // Remove the course with the longest duration
      totalTime -= maxHeap.top();
      maxHeap.pop();
    }
  }

  return static_cast<int>(maxHeap.size());
}

CourseScheduleIiiSolution::CourseScheduleIiiSolution() {
  setMetaInfo({.id = 630, .title = "Course Schedule III",
               .url = "https://leetcode.com/problems/course-schedule-iii/"});
  registerStrategy(
      {.name = "GreedyWithMaxHeap",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Sorting", "Heap (Priority Queue)"}},
      scheduleCourseImpl);
}

int CourseScheduleIiiSolution::scheduleCourse(
    std::vector<std::vector<int>>& courses) {
  return getSolution()(courses);
}

}  // namespace leetcode::problem_630
