#include "shell.hpp"

#include <iostream>

#include "../parser/comment_parser.hpp"
#include "../parser/group_parser.hpp"

#define MAX_INPUT_SIZE 256

Shell::Shell() {}

Shell::~Shell() {}

void Shell::run() {
  char user_input[MAX_INPUT_SIZE] = "echo \"hello world\" # hi \"test\"";

  // get user input
  // this->print_prompt();
  // std::cin.getline(user_input, MAX_INPUT_SIZE);

  // parse input
  CommentParser comment_parser(user_input);
  comment_parser.print_unparsed();
  std::string line_with_no_comments = comment_parser.parse();
  comment_parser.print_parsed();

  GroupParser g_parser(line_with_no_comments);
  g_parser.parse();
}

void Shell::print_prompt() { std::cout << "$ "; }