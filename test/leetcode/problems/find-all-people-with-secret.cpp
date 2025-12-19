#include "leetcode/problems/find-all-people-with-secret.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2092 {

class FindAllPeopleWithSecretTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindAllPeopleWithSecretSolution solution;
};

TEST_P(FindAllPeopleWithSecretTest, Example1) {
  int n = 6;
  vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
  int firstPerson = 1;
  vector<int> expected = {0, 1, 2, 3, 5};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

TEST_P(FindAllPeopleWithSecretTest, Example2) {
  int n = 4;
  vector<vector<int>> meetings = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}};
  int firstPerson = 3;
  vector<int> expected = {0, 1, 3};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

TEST_P(FindAllPeopleWithSecretTest, Example3) {
  int n = 5;
  vector<vector<int>> meetings = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
  int firstPerson = 1;
  vector<int> expected = {0, 1, 2, 3, 4};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

TEST_P(FindAllPeopleWithSecretTest, SinglePerson) {
  int n = 1;
  vector<vector<int>> meetings = {};
  int firstPerson = 0;
  vector<int> expected = {0};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

TEST_P(FindAllPeopleWithSecretTest, NoMeetings) {
  int n = 3;
  vector<vector<int>> meetings = {};
  int firstPerson = 1;
  vector<int> expected = {0, 1};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

TEST_P(FindAllPeopleWithSecretTest, SequentialMeetings) {
  int n = 4;
  vector<vector<int>> meetings = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}};
  int firstPerson = 0;
  vector<int> expected = {0, 1, 2, 3};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

TEST_P(FindAllPeopleWithSecretTest, DisconnectedGroups) {
  int n = 6;
  vector<vector<int>> meetings = {{0, 1, 1}, {2, 3, 1}, {4, 5, 2}};
  int firstPerson = 0;
  vector<int> expected = {0, 1};
  vector<int> result = solution.findAllPeople(n, meetings, firstPerson);
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FindAllPeopleWithSecretTest,
    ::testing::ValuesIn(FindAllPeopleWithSecretSolution().getStrategyNames()));

}  // namespace problem_2092
}  // namespace leetcode