#include "./connector_parser.hpp"

#include <string>
#include <vector>

std::vector<std::string> ConnectorParser::parse() {
  //  Here we keep track the current connector token we are looking at before
  //  next character
  std::string curr_connector = "";
  //  Here we keep track the current string token we are looking at before next
  //  character
  std::string curr_string = "";

  for (auto unparsed_token : this->unparsed_tokens) {
    for (auto character : unparsed_token) {
    }
  }
}

void ConnectorParser::print_unparsed() {}