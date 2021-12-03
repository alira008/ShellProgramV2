#include "./postfixer.hpp"

#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> Postfixer::convert() {
  std::stack<std::string> opStack;
  std::vector<std::string> postfixTokens;
  std::vector<std::string> command;
  std::vector<std::vector<std::string>> commandList;

  for (auto token : infixTokens) {
    //  If token is operand, push to postFixTokens
    if (!ops.isOperator(token)) command.push_back(token);
    //  else our token is an operator
    else {
      //  Push the command into our list of commands when we find an operator
      if (!command.empty()) {
        commandList.push_back(command);
        command.clear();
      }

      if ((!opStack.empty() && ops.isEqlOrHigher(token, opStack.top())) ||
          opStack.empty() || token == "(") {
        //  Push operator into the stack
        opStack.push(token);

      } else if (!ops.isEqlOrHigher(token, opStack.top())) {
        //  Pop all operators
        while (!opStack.empty() && opStack.top() != "(") {
          std::vector<std::string> opVec = {opStack.top()};
          commandList.push_back(opVec);
          opStack.pop();
        }
        opStack.push(token);
      } else if (token == ")") {
        //  Pop all operators until we find a "("
        while (opStack.top() != "(" && !opStack.empty()) {
          std::vector<std::string> opVec = {opStack.top()};
          commandList.push_back(opVec);
          opStack.pop();
        }
        opStack.pop();
      }
    }
  }

  //  Pop other commands
  while (!command.empty()) {
    commandList.push_back(command);
    command.clear();
  }

  //  Pop stack of operators
  while (!opStack.empty()) {
    std::vector<std::string> opVec = {opStack.top()};
    commandList.push_back(opVec);
    opStack.pop();
  }

  return commandList;
}