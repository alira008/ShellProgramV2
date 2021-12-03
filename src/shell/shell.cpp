#include "shell.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "../cmdline/cmdline_composite.hpp"
#include "../parser/comment_parser.hpp"
#include "../parser/composite_parser.hpp"
#include "../parser/connector_parser.hpp"
#include "../parser/group_parser.hpp"
#include "../postfixer/postfixer.hpp"

Shell::Shell() {}

Shell::~Shell() {}

void Shell::run() {
  while (true) {
    //  Location where user input is stored
    std::string userInput;

    // get user input
    this->print_prompt();
    std::getline(std::cin, userInput);

    // Put user_input into a vector for parsing
    std::vector<std::string> user_input_vec = {userInput};

    //  First we make pointers to the parsers we want to use
    //  CommentParser parses comments '#' from user input
    //  GroupParser parses [] () from user's input
    //  ConnectorParser parses ' ', ';', '|', and '&' from user's input
    Parser *comment_parser = new CommentParser(),
           *group_parser = new GroupParser(),
           *connector_parser = new ConnectorParser();

    //  Creating our CompositeParser which will do all the parsing we want. This
    //  object deletes all Parser * that were added to it. They are deleted in
    //  the destructor.
    CompositeParser full_parser(user_input_vec);

    //  Here we add the parsers we want the CompositeParser to use
    full_parser.add(comment_parser);
    full_parser.add(group_parser);
    full_parser.add(connector_parser);

    //  Tell our CompositeParser to give us the parsed_tokens
    std::vector<std::string> parsed_tokens = full_parser.parse();

    Postfixer toPostFix(parsed_tokens);
    std::vector<std::vector<std::string>> commandList = toPostFix.convert();

    CmdlineComposite cmdline(commandList);
    cmdline.execute();
  }
}

void Shell::print_prompt() { std::cout << "$ "; }