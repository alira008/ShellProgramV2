#ifndef __CONNECTOR_PARSER_HPP__
#define __CONNECTOR_PARSER_HPP__

#include <string>
#include <vector>

#include "./vector_parser.hpp"

class ConnectorParser {
 private:
  std::vector<std::string> unparsed_tokens;
  std::vector<char> delimiters = {' ', '|', '&', ';'};

 public:
  ConnectorParser(){};
  ConnectorParser(std::vector<std::string> semiparsed_tokens)
      : unparsed_tokens(semiparsed_tokens){};
  ~ConnectorParser(){};
  std::vector<std::string> parse();
  void print_unparsed();
};

#endif