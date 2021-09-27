#ifndef __GROUP_PARSER_HPP__
#define __GROUP_PARSER_HPP__

#include <string>
#include <vector>

#include "./parser.hpp"

class GroupParser : public Parser {
 private:
  std::vector<char> delimiters = {'[', ']', '(', ')'};
  bool is_char_delimiter(const char character);
  void countDelims(char character, int (&paren_cnt)[2], int (&bracket_cnt)[2]);

 public:
  GroupParser(){};
  GroupParser(std::vector<std::string> unparsed_tokens)
      : Parser{unparsed_tokens} {};
  ~GroupParser(){};
  std::vector<std::string> parse();
  void print_unparsed();
  void print_parsed();
};

#endif