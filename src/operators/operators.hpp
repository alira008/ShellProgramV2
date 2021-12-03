#ifndef __OPERATORS_HPP__
#define __OPERATORS_HPP__
#include <string>
#include <unordered_map>
#include <vector>

class Operators {
 private:
  const std::vector<std::string> operators = {"&&", "||", ";",  "[", "]", "|",
                                              "<",  ">",  ">>", "(", ")"};
  const std::unordered_map<std::string, int> precedenceOps = {
      {"&&", 3}, {"||", 3}, {";", 3}, {"<", 4}, {">", 4}, {">>", 4}, {"|", 4}};

  int precedence(std::string op);

 public:
  Operators(){};
  ~Operators(){};
  bool isOperator(std::string str);
  bool isEqlOrHigher(std::string op1, std::string op2);
};

#endif