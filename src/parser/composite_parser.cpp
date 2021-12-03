#include "./composite_parser.hpp"

#include <string>
#include <vector>

#include "./parser.hpp"

CompositeParser::~CompositeParser() {
  for (auto parser : this->child_parsers) {
    delete (parser);
  }
}

void CompositeParser::add(Parser *parser) {
  this->child_parsers.push_back(parser);
}

void CompositeParser::remove(Parser *parser) {
  int parser_loc = -1;
  for (int i = 0; i < this->child_parsers.size(); ++i) {
    if (this->child_parsers[i] == parser) parser_loc = i;
  }

  //  If parser exists in our vector, we erase it.
  if (parser_loc >= 0) {
    this->child_parsers.erase(this->child_parsers.begin() + parser_loc);
    delete (parser);
  }
}

std::vector<std::string> CompositeParser::parse() {
  std::vector<std::string> result = this->unparsed_tokens;
  for (auto parser : this->child_parsers) {
    parser->set_unparsed_tokens(result);
    result = parser->parse();
  }
  this->parsed_tokens = result;
  return result;
}