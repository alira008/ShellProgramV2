#ifndef __GROUP_PARSER_HPP__
#define __GROUP_PARSER_HPP__

#include <string>
#include <vector>

#include "./vector_parser.hpp"

class GroupParser : private VectorParser {
 private:
  std::string unparsed_line;
  std::vector<char> delimiters = {'[', ']', '(', ')'};
  bool is_char_delim(const char character);
  void countDelims(char character, int (&paren_cnt)[2], int (&bracket_cnt)[2]);

 public:
  GroupParser(){};
  GroupParser(std::string line_with_no_comments)
      : unparsed_line(line_with_no_comments){};
  ~GroupParser(){};
  std::vector<std::string> parse();
  void print_unparsed();
};

#endif