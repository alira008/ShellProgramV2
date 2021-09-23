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
  std::string cur_str = "";
  int paren_cnt[2] = {0}, bracket_cnt[2] = {0};

  for (auto character : this->unparsed_line) {
    //   Check if character is one of delimiters
    //  If character is a delim, we push current string and delim into token
    //  list
    if (is_char_delim(character)) {
      if (!cur_str.empty()) this->tokens.push_back(cur_str);
      cur_str = character;
      this->tokens.push_back(cur_str);
      cur_str.clear();
    } else {
      cur_str += character;
    }

    //  Incremenet amount of delimiters
    this->countDelims(character, paren_cnt, bracket_cnt);
  }

  if (paren_cnt[0] != paren_cnt[1] || bracket_cnt[0] != bracket_cnt[1]) {
    std::cout << "Error: unmatching brackets/parentheses" << std::endl;
  }

  for (auto token : this->tokens) {
    std::cout << token << std::endl;
  }

  return this->tokens;
}

void GroupParser::print_unparsed() {
  std::cout << this->unparsed_line << std::endl;
}