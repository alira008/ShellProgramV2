#ifndef __STRING_PARSER_HPP__
#define __STRING_PARSER_HPP__

#include <string>

#include "./parser.hpp"

class StringParser : public Parser {
 protected:
  const std::string unparsed_line;

 public:
  StringParser(){};
  StringParser(const char* user_input) : unparsed_line(user_input){};
  ~StringParser(){};
  virtual std::string parse() = 0;
};

#endif