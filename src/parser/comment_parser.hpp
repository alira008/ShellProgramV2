#ifndef __COMMENT_PARSER_HPP__
#define __COMMENT_PARSER_HPP__

#include <string>
#include <vector>

#include "./parser.hpp"

class CommentParser : public Parser {
 private:
  // data
 public:
  CommentParser(){};
  CommentParser(std::vector<std::string> user_input) : Parser(user_input){};
  ~CommentParser(){};
  std::vector<std::string> parse();
  void print_unparsed();
  void print_parsed();
};

#endif