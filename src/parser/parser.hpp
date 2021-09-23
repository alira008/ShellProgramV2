#ifndef __PARSER_HPP__
#define __PARSER_HPP__
#include <string>
#include <vector>

class Parser {
 private:
  //  data
 public:
  Parser(){};
  ~Parser(){};
  virtual void print_unparsed() = 0;
};

#endif