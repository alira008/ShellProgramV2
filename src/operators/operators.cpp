#include "./operators.hpp"

bool Operators::isOperator(std::string str) {
  for (auto op : operators) {
    if (str == op) return true;
  }
  return false;
}

int Operators::precedence(std::string op) {
  std::unordered_map<std::string, int>::const_iterator precedenceOpIt =
      precedenceOps.find(op);
  if (precedenceOpIt == precedenceOps.end())
    throw "Invalid operator given to check precedence";
  return precedenceOpIt->second;
}

bool Operators::isEqlOrHigher(std::string op1, std::string op2) {
  int p1 = precedence(op1);
  int p2 = precedence(op2);

  return p1 >= p2 ? true : false;
}