#include "./group_parser.hpp"

#include <iostream>
#include <string>
#include <vector>

bool GroupParser::is_char_delimiter(const char character) {
  for (auto delim : this->delimiters) {
    if (delim == character) return true;
  }
  return false;
}

void GroupParser::countDelims(char character, int (&paren_cnt)[2],
                              int (&bracket_cnt)[2]) {
  if (character == '(') {
    ++paren_cnt[0];
  } else if (character == ')') {
    ++paren_cnt[1];
  } else if (character == '[') {
    ++bracket_cnt[0];
  } else if (character == ']') {
    ++bracket_cnt[1];
  }
}

std::vector<std::string> GroupParser::parse() {
  std::string curr_str = "";
  int paren_cnt[2] = {0}, bracket_cnt[2] = {0};
  //  Loop through all unparsed_tokens
  for (auto unparsed_token : this->unparsed_tokens) {
    //  Loop through all characters of unparsed_token
    for (int i = 0; i < unparsed_token.length(); ++i) {
      //  Check if character is one of delimiters
      //  If character is a delim, we push current string and delim into token
      //  list
      if (this->is_char_delimiter(unparsed_token[i])) {
        if (!curr_str.empty()) this->parsed_tokens.push_back(curr_str);

        // We push character into our parsed_tokens since it is a delimiter
        curr_str = unparsed_token[i];
        this->parsed_tokens.push_back(curr_str);
        curr_str.clear();
      } else if (unparsed_token[i] == '\"') {
        //  Our substring that includes only the string literal
        std::string string_literal =
            this->add_string_literal(unparsed_token, i);

        //  add our string literal to our current string
        if (string_literal.length() != 0) curr_str += string_literal;
      } else {
        curr_str += unparsed_token[i];
      }

      //  Increment amount of delimiters
      this->countDelims(unparsed_token[i], paren_cnt, bracket_cnt);
    }

    if (!curr_str.empty()) {
      parsed_tokens.push_back(curr_str);
      curr_str.clear();
    }

    if (paren_cnt[0] != paren_cnt[1] || bracket_cnt[0] != bracket_cnt[1]) {
      std::cout << "Error: unmatching brackets/parentheses" << std::endl;
    }
  }

  if (!curr_str.empty()) this->parsed_tokens.push_back(curr_str);

  return this->parsed_tokens;
}

void GroupParser::print_unparsed() {
  std::cout << "From Group Parser - Unparsed line: " << std::endl;
  Parser::print_unparsed();
  std::cout << "End of Group Parser\n" << std::endl;
}

void GroupParser::print_parsed() {
  std::cout << "From Group Parser - Parsed line: " << std::endl;
  Parser::print_parsed();
  std::cout << "End of Group Parser\n" << std::endl;
}