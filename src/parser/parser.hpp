#ifndef __PARSER_HPP__
#define __PARSER_HPP__
#include <string>
#include <vector>

class Parser {
 protected:
  std::vector<std::string> unparsed_tokens;
  std::vector<std::string> parsed_tokens;
  std::string add_string_literal(const std::string unparsed_str, int &i);

 public:
  Parser(){};
  Parser(std::vector<std::string> user_input) : unparsed_tokens{user_input} {};
  virtual ~Parser(){};
  virtual std::vector<std::string> parse() = 0;
  virtual void set_unparsed_tokens(std::vector<std::string> unparsed_tokens);
  virtual void print_unparsed();
  virtual void print_parsed();
};

#endif