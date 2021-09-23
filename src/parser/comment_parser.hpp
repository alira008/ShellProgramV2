#ifndef __COMMENT_PARSER_HPP__
#define __COMMENT_PARSER_HPP__

#include <string>

#include "./string_parser.hpp"

class CommentParser : private StringParser {
 private:
  std::string parsed_line;

 public:
  CommentParser();
  CommentParser(const char* user_input) : StringParser(user_input){};
  ~CommentParser(){};
  std::string parse();
  void print_unparsed();
  void print_parsed();
};

// std::vector<std::string> tokens

#endif