#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__
#include <sys/wait.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "./cmdline.hpp"

class Command : public Cmdline {
 private:
  char **argumentList = nullptr;

 public:
  Command();
  Command(std::vector<std::string> argumentVec);
  ~Command();
  int execute(int inputFile = 0, int outputFile = 1);
  void setArgumentList(std::vector<std::string> argumentVec);
  const char *const getFilename() { return argumentList[0]; }
  void print();
};

#endif