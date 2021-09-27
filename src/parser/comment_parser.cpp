#include "./comment_parser.hpp"

#include <iostream>
#include <string>

// Function used to separate comments from token list
// If we find " " in unparsed_line we can ignore the contents inside it.
// Only when a '#' is outside double quotes we can remove it from our commands
// that need to execute
std::vector<std::string> CommentParser::parse() {
  // Loop through every unparsed token
  for (auto unparsed_token : this->unparsed_tokens) {
    //  If comment is found in unparsed_token set comment_found to true
    bool comment_found = false;

    //  Length of unparsed_token
    int unparsed_token_len = unparsed_token.length();

    //  Parsed line we will be pushing to our parsed_tokens vector
    std::string line_without_comments = unparsed_token;

    for (int i = 0; i < unparsed_token_len && !comment_found; ++i) {
      //  Here we set save the character we are looking at into a const char
      //  variable
      const char character = unparsed_token[i];

      if (character == '\"') {
        //  Starting from the position after this starting quote, we check the
        //  location of the end quote
        size_t end_quote_loc = unparsed_token.find(character, i + 1);

        //  We only set current i to the location of the end quote if it exists
        //  and we found it in the line above
        if (end_quote_loc != std::string::npos) i = end_quote_loc;
      } else if (character == '#') {
        //  Here we get the substring that has everything before the '#'
        line_without_comments = unparsed_token.substr(0, i);

        //  We set commentFound to true so that we can exit the while loop
        comment_found = true;
      }
    };
    //  Push line without comment into parsed_tokens vector
    this->parsed_tokens.push_back(line_without_comments);
  }

  // return our parsed tokens
  return this->parsed_tokens;
}

void CommentParser::print_unparsed() {
  std::cout << "From Comment Parser - Unparsed line: " << std::endl;
  Parser::print_unparsed();
  std::cout << "End of Comment Parser\n" << std::endl;
}

void CommentParser::print_parsed() {
  std::cout << "From Comment Parser - Parsed line: " << std::endl;
  Parser::print_parsed();
  std::cout << "End of Comment Parser\n" << std::endl;
}