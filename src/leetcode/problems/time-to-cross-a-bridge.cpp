#include "leetcode/problems/time-to-cross-a-bridge.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2532 {

namespace {

struct CrossEvent {
  long long time;
  int worker;
  int type;  // 0 = arrivedLeft (start put), 1 = arrivedRight (start pick)
             // 2 = donePut (worker back to left-waiting), 3 = donePick (worker to right-waiting)
};

struct EventComparator {
  bool operator()(const CrossEvent& a, const CrossEvent& b) const {
    if (a.time != b.time) return a.time > b.time;
    if (a.worker != b.worker) return a.worker > b.worker;
    return a.type > b.type;
  }
};

// Less-efficient worker should be served first:
// higher (left+right), then higher index. Since time is in worker order,
// higher index => larger id.
using WorkerPQ =
    std::priority_queue<int, std::vector<int>,
                        std::function<bool(int, int)>>;  // created with custom cmp

}  // namespace

namespace {

int findCrossingTimeImpl(int n, int k, std::vector<std::vector<int>>& time) {
  // Efficiency comparator: the LESS efficient worker goes first.
  // Efficiency key = time[i][0] (right) + time[i][2] (left).
  auto cmp = [&time](int a, int b) {
    int ea = time[a][0] + time[a][2];
    int eb = time[b][0] + time[b][2];
    if (ea != eb) return ea < eb;  // want bigger first (less efficient first)
    return a < b;                  // want bigger id first (less efficient first)
  };

  // k up to 1e4, build vector + custom heap via priority_queue with comparator
  std::priority_queue<int, std::vector<int>, decltype(cmp)> leftWaiting(cmp);
  std::priority_queue<int, std::vector<int>, decltype(cmp)> rightWaiting(cmp);

  for (int i = 0; i < k; ++i) leftWaiting.push(i);

  std::priority_queue<CrossEvent, std::vector<CrossEvent>, EventComparator> events;

  int boxes = n;
  long long curTime = 0;
  long long lastArriveLeft = 0;
  int arrivedLeftBoxes = 0;

  while (arrivedLeftBoxes < n) {
    // 1. Process all events that complete at or before curTime.
    while (!events.empty() && events.top().time <= curTime) {
      CrossEvent ev = events.top();
      events.pop();
      int w = ev.worker;
      long long doneAt = ev.time;
      if (ev.type == 2) {            // donePut
        leftWaiting.push(w);
      } else if (ev.type == 3) {     // donePick
        rightWaiting.push(w);
      } else if (ev.type == 0) {     // arrivedLeft -> start put
        lastArriveLeft = doneAt;
        ++arrivedLeftBoxes;
        long long putDone = doneAt + time[w][3];
        events.push({putDone, w, 2});
      } else {                       // arrivedRight -> start pick
        long long pickDone = doneAt + time[w][1];
        events.push({pickDone, w, 3});
      }
    }

    // 2. Bridge is free at curTime. Dispatch.
    if (!rightWaiting.empty()) {
      int w = rightWaiting.top();
      rightWaiting.pop();
      long long arriveLeftAt = curTime + time[w][2];
      events.push({arriveLeftAt, w, 0});
      curTime = arriveLeftAt;
      continue;
    }
    if (!leftWaiting.empty() && boxes > 0) {
      int w = leftWaiting.top();
      leftWaiting.pop();
      --boxes;
      long long arriveRightAt = curTime + time[w][0];
      events.push({arriveRightAt, w, 1});
      curTime = arriveRightAt;
      continue;
    }

    // 3. Bridge free but cannot dispatch; advance time to next event.
    if (events.empty()) break;  // no pending work (should not happen while boxes<n)
    curTime = events.top().time;
  }

  return static_cast<int>(lastArriveLeft);
}

}  // namespace

TimeToCrossABridgeSolution::TimeToCrossABridgeSolution() {
  this->setMetaInfo({.id = 2532,
                     .title = "Time to Cross a Bridge",
                     .url = "https://leetcode.com/problems/time-to-cross-a-bridge/"});
  this->registerStrategy(
      {.name = "EventDrivenHeap",
       .expected = "Accepted",
       .time_complexity = "O((n + k) log k)",
       .space_complexity = "O(k)",
       .tags = {"Heap", "Priority Queue", "Simulation"}},
      [](int n, int k, std::vector<std::vector<int>>& t) {
        return findCrossingTimeImpl(n, k, t);
      });
}

int TimeToCrossABridgeSolution::findCrossingTime(int n, int k,
                                                std::vector<std::vector<int>>& time) {
  return this->getSolution()(n, k, time);
}

}  // namespace problem_2532
}  // namespace leetcode
