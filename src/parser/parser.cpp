#include "./parser.hpp"

#include <iostream>

void Parser::set_unparsed_tokens(std::vector<std::string> unparsed_tokens) {
  this->unparsed_tokens = unparsed_tokens;
}

void Parser::print_unparsed() {
  for (auto token : this->unparsed_tokens) {
    std::cout << "\t" << token << std::endl;
  }
}

void Parser::print_parsed() {
  for (auto token : this->parsed_tokens) {
    std::cout << "\t" << token << std::endl;
  }
}

// @param unparsed_str: The string we want to search for the string literal
// @param i: The reference of the position we are searching in unparsed_str. At
// the end of the function, we change this value to the position of the end
// quote
// @returns A string literal inside the given string from the position i
std::string Parser::add_string_literal(const std::string unparsed_str, int &i) {
  // Here we store the string literal we are returning
  std::string string_literal = "";
  //  Here we store the location of the closing quote \"
  int next_quote_loc = unparsed_str.find('\"', i + 1);

  //  We want to check we have found the closing quote before adding the
  //  string literal to current string
  if (next_quote_loc != std::string::npos) {
    //  The amount of characters inside the string literal including the
    //  quotes
    int string_literal_len = next_quote_loc - i + 1;

    //  Our substring that includes only the string literal
    string_literal = unparsed_str.substr(i, string_literal_len);

    //  next iteration can now skip string literal
    i = next_quote_loc;
  }

  return string_literal;
}