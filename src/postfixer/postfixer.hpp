#ifndef __POSTFIXER_HPP__
#define __POSTFIXER_HPP__
#include <string>
#include <vector>

#include "../operators/operators.hpp"

class Postfixer {
 private:
  std::vector<std::string> infixTokens;
  Operators ops;

 public:
  Postfixer(std::vector<std::string> myInfixTokens)
      : infixTokens(myInfixTokens) {}
  ~Postfixer() {}

  std::vector<std::vector<std::string>> convert();
};

#endif