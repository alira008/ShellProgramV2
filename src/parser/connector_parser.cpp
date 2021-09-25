#include "./connector_parser.hpp"

#include <iostream>
#include <string>
#include <vector>

bool ConnectorParser::is_char_delimiter(const char character) {
  for (auto delimiter : delimiters) {
    if (character == delimiter) return true;
  }
  return false;
}

std::vector<std::string> ConnectorParser::parse() {
  //  Here we keep track the current connector token we are looking at before
  //  next character
  std::string curr_connector = "";
  //  Here we keep track the current string token we are looking at before next
  //  character
  std::string curr_str = "";

  // loop over all unparsed tokens in vector
  for (auto unparsed_token : this->unparsed_tokens) {
    // loop over all characters in unparsed token string
    for (int i = 0; i < unparsed_token.length(); ++i) {
      // check if our character is a delimiter
      if (this->is_char_delimiter(unparsed_token[i])) {
        if (!curr_str.empty()) this->tokens.push_back(curr_str);

        // if we find a space, we remove it
        if (unparsed_token[i] != ' ') {
          curr_connector += unparsed_token[i];
        }
        curr_str.clear();

        //  if our character is a \", then we want to skip over all
      } else if (unparsed_token[i] == '\"') {
        //  Here we store our string literal
        //  if we do not find the end quote, we do not change the value of i
        std::string string_literal =
            this->add_string_literal(unparsed_token, i);

        // If we do find the end quote, we add the string literal to curr_str
        if (string_literal.length() != 0) curr_str += string_literal;

        // if it's not a delimiter
      } else {
        if (!curr_connector.empty()) this->tokens.push_back(curr_connector);

        curr_connector.clear();
        curr_str += unparsed_token[i];
      }
    }
  }
  if (!curr_str.empty()) tokens.push_back(curr_str);
  if (!curr_connector.empty()) tokens.push_back(curr_connector);

  return this->tokens;
}

void ConnectorParser::print_unparsed() {
  std::cout << "From Connector Parser - Unparsed line: " << std::endl;
  for (auto token : this->unparsed_tokens) {
    std::cout << token << std::endl;
  }
  std::cout << "End of Connector Parser" << std::endl;
}

void ConnectorParser::print_parsed() {
  std::cout << "From Connector Parser - Parsed line: " << std::endl;
  for (auto token : this->tokens) {
    std::cout << "\t" << token << std::endl;
  }
  std::cout << "End of Connector Parser" << std::endl;
}