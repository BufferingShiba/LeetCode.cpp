#include <gtest/gtest.h>

#include "leetcode/problems/reward-top-k-students.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2512 {
namespace {

class RewardTopKStudentsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RewardTopKStudentsSolution solution_;
};

TEST_P(RewardTopKStudentsTest, Example1) {
  std::vector<std::string> positive_feedback = {"smart", "brilliant",
                                                  "studious"};
  std::vector<std::string> negative_feedback = {"not"};
  std::vector<std::string> report = {"this student is studious",
                                     "the student is smart"};
  std::vector<int> student_id = {1, 2};
  int k = 2;
  auto result = solution_.topStudents(positive_feedback, negative_feedback,
                                      report, student_id, k);
  EXPECT_EQ(result, (std::vector<int>{1, 2}));
}

TEST_P(RewardTopKStudentsTest, Example2) {
  std::vector<std::string> positive_feedback = {"smart", "brilliant",
                                                  "studious"};
  std::vector<std::string> negative_feedback = {"not"};
  std::vector<std::string> report = {"this student is not studious",
                                     "the student is smart"};
  std::vector<int> student_id = {1, 2};
  int k = 2;
  auto result = solution_.topStudents(positive_feedback, negative_feedback,
                                      report, student_id, k);
  EXPECT_EQ(result, (std::vector<int>{2, 1}));
}

TEST_P(RewardTopKStudentsTest, SelfAuthoredSingleStudent) {
  std::vector<std::string> positive_feedback = {"good"};
  std::vector<std::string> negative_feedback = {"bad"};
  std::vector<std::string> report = {"good good bad"};
  std::vector<int> student_id = {42};
  int k = 1;
  auto result = solution_.topStudents(positive_feedback, negative_feedback,
                                      report, student_id, k);
  EXPECT_EQ(result, (std::vector<int>{42}));
}

TEST_P(RewardTopKStudentsTest, SelfAuthoredTieById) {
  std::vector<std::string> positive_feedback = {"excellent"};
  std::vector<std::string> negative_feedback = {};
  std::vector<std::string> report = {"excellent", "excellent", "excellent"};
  std::vector<int> student_id = {10, 5, 7};
  int k = 3;
  auto result = solution_.topStudents(positive_feedback, negative_feedback,
                                      report, student_id, k);
  // All have same points (3), tie-break by lower ID first.
  EXPECT_EQ(result, (std::vector<int>{5, 7, 10}));
}

TEST_P(RewardTopKStudentsTest, SelfAuthoredTopKPartial) {
  std::vector<std::string> positive_feedback = {"wow"};
  std::vector<std::string> negative_feedback = {"meh"};
  std::vector<std::string> report = {"wow", "meh", "wow wow"};
  std::vector<int> student_id = {1, 2, 3};
  int k = 2;
  auto result = solution_.topStudents(positive_feedback, negative_feedback,
                                      report, student_id, k);
  // Student 3: 6 pts, Student 1: 3 pts, Student 2: -1 pt
  EXPECT_EQ(result, (std::vector<int>{3, 1}));
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, RewardTopKStudentsTest,
    testing::ValuesIn(RewardTopKStudentsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2512
}  // namespace leetcode
