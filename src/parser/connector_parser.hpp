#ifndef __CONNECTOR_PARSER_HPP__
#define __CONNECTOR_PARSER_HPP__

#include <string>
#include <vector>

#include "./parser.hpp"

class ConnectorParser : public Parser {
 private:
  std::vector<char> delimiters = {' ', '|', '&', ';'};
  bool is_char_delimiter(char character);

 public:
  ConnectorParser(){};
  ConnectorParser(std::vector<std::string> unparsed_tokens)
      : Parser(unparsed_tokens){};
  ~ConnectorParser(){};
  std::vector<std::string> parse();
  void print_unparsed();
  void print_parsed();
};

#endif