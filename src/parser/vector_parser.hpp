#ifndef __VECTOR_PARSER_HPP__
#define __VECTOR_PARSER_HPP__

#include <string>
#include <vector>

#include "./parser.hpp"

class VectorParser : public Parser {
 protected:
  std::vector<std::string> tokens;

 public:
  VectorParser(){};
  VectorParser(std::vector<std::string> semiparsed_tokens)
      : tokens(semiparsed_tokens){};
  ~VectorParser(){};
  virtual std::vector<std::string> parse() = 0;
};

#endif