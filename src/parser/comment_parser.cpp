#include "./comment_parser.hpp"

#include <iostream>
#include <string>

CommentParser::CommentParser() {}

// Function used to separate comments from token list
// If we find " " in unparsed_line we can ignore the contents inside it.
// Only when a '#' is outside double quotes we can remove it from our commands
// that need to execute
std::string CommentParser::parse() {
  bool commentFound = false;
  size_t i = 0, line_size = this->unparsed_line.length();
  std::string line_without_comments = this->unparsed_line;

  while (i < line_size && !commentFound) {
    // Here we set save the character we are looking at into a const char
    // variable
    const char character = this->unparsed_line[i];

    if (character == '\"') {
      //  Starting from the position after this starting quote, we check the
      //  location of the end quote
      size_t end_quote_loc = this->unparsed_line.find(character, i + 1);

      //  We only set current i to the location of the end quote if it exists
      //  and we found it in the line above
      if (end_quote_loc != std::string::npos) i = end_quote_loc;
    } else if (character == '#') {
      //  Here we get the substring that has everything before the '#'
      line_without_comments = this->unparsed_line.substr(0, i);

      //  We set commentFound to true so that we can exit the while loop
      commentFound = true;
    }

    // Check the whole unparsed_line
    ++i;
  };

  this->parsed_line = line_without_comments;
  return this->parsed_line;
}

void CommentParser::print_unparsed() {
  std::cout << "Unparsed line: " << this->unparsed_line << std::endl;
}

void CommentParser::print_parsed() {
  std::cout << "Parsed line: " << this->parsed_line << std::endl;
}