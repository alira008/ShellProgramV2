#include "./group_parser.hpp"

#include <iostream>
#include <string>
#include <vector>

bool GroupParser::is_char_delim(const char character) {
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

  for (int i = 0; i < this->unparsed_line.length(); ++i) {
    //  Check if character is one of delimiters
    //  If character is a delim, we push current string and delim into token
    //  list

    if (this->is_char_delim(this->unparsed_line[i])) {
      if (!curr_str.empty()) this->tokens.push_back(curr_str);
      curr_str = this->unparsed_line[i];
      this->tokens.push_back(curr_str);
      curr_str.clear();
    } else if (this->unparsed_line[i] == '\"') {
      //  Our substring that includes only the string literal
      std::string string_literal =
          this->add_string_literal(this->unparsed_line, i);

      //  add our string literal to our current string
      if (string_literal.length() != 0) curr_str += string_literal;
    } else {
      curr_str += this->unparsed_line[i];
    }

    //  Increment amount of delimiters
    this->countDelims(this->unparsed_line[i], paren_cnt, bracket_cnt);
  }

  if (!curr_str.empty()) this->tokens.push_back(curr_str);

  if (paren_cnt[0] != paren_cnt[1] || bracket_cnt[0] != bracket_cnt[1]) {
    std::cout << "Error: unmatching brackets/parentheses" << std::endl;
  }

  return this->tokens;
}

void GroupParser::print_unparsed() {
  std::cout << this->unparsed_line << std::endl;
}

void GroupParser::print_parsed() {
  std::cout << "From Group Parser - Parsed line: " << std::endl;
  for (auto token : this->tokens) {
    std::cout << "\t" << token << std::endl;
  }
  std::cout << "End of Group Parser" << std::endl;
}