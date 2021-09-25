#include "shell.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "../parser/comment_parser.hpp"
#include "../parser/connector_parser.hpp"
#include "../parser/group_parser.hpp"

#define MAX_INPUT_SIZE 256

Shell::Shell() {}

Shell::~Shell() {}

void Shell::run() {
  char user_input[MAX_INPUT_SIZE] =
      "echo \"[hello] || (world)\" && cd ./directory # hi \"test\"";

  // get user input
  // this->print_prompt();
  // std::cin.getline(user_input, MAX_INPUT_SIZE);

  // Parse comments '#' from user input
  CommentParser comment_parser(user_input);
  std::string line_with_no_comments = comment_parser.parse();
  // comment_parser.print_unparsed();

  // Parse [] () from user's input
  GroupParser grouping_parser(line_with_no_comments);
  std::vector<std::string> semiparsed_tokens = grouping_parser.parse();

  // Parse ' ', ';', '|', and '&' from user's input
  ConnectorParser connector_parser(semiparsed_tokens);
  std::vector<std::string> parsed_tokens = connector_parser.parse();
  // connector_parser.print_parsed();
}

void Shell::print_prompt() { std::cout << "$ "; }