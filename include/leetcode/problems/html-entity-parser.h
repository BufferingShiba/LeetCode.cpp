#ifndef LEETCODE_PROBLEMS_HTML_ENTITY_PARSER_H__
#define LEETCODE_PROBLEMS_HTML_ENTITY_PARSER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1410 {

using Func = std::function<std::string(const std::string&)>;

class HtmlEntityParserSolution : public SolutionBase<Func> {
 public:
  std::string entityParser(const std::string& text);

  HtmlEntityParserSolution();
};

}  // namespace leetcode::problem_1410

#endif  // LEETCODE_PROBLEMS_HTML_ENTITY_PARSER_H__
