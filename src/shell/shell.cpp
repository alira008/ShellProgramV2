#include "shell.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "../parser/comment_parser.hpp"
#include "../parser/composite_parser.hpp"
#include "../parser/connector_parser.hpp"
#include "../parser/group_parser.hpp"

#define MAX_INPUT_SIZE 256

Shell::Shell() {}

Shell::~Shell() {}

void Shell::run() {
  char user_input[MAX_INPUT_SIZE] =
      "echo \"[hello] || (world)\" [hi] | cd ./directory ;||# hi \"test\"";

  // get user input
  // this->print_prompt();
  // std::cin.getline(user_input, MAX_INPUT_SIZE);

  // Put user_input into a vector for parsing
  std::vector<std::string> user_input_vec = {user_input};

  //  First we make pointers to the parsers we want to use
  //  CommentParser parses comments '#' from user input
  //  GroupParser parses [] () from user's input
  //  ConnectorParser parses ' ', ';', '|', and '&' from user's input
  Parser *comment_parser = new CommentParser(),
         *group_parser = new GroupParser(),
         *connector_parser = new ConnectorParser();

  //  Creating our CompositeParser which will do all the parsing we want. This
  //  object deletes all Parser * that were added to it. They are deleted in the
  //  destructor.
  CompositeParser full_parser(user_input_vec);

  //  Here we add the parsers we want the CompositeParser to use
  full_parser.add(comment_parser);
  full_parser.add(group_parser);
  full_parser.add(connector_parser);

  //  Tell our CompositeParser to give us the parsed_tokens
  std::vector<std::string> parsed_tokens = full_parser.parse();

  //  Set dangling pointers to nullptr
  comment_parser = nullptr;
  group_parser = nullptr;
  connector_parser = nullptr;
}

void Shell::print_prompt() { std::cout << "$ "; }