#ifndef __EXIT_HPP__
#define __EXIT_HPP__
#include <string>
#include <vector>

#include "./command.hpp"

class Exit : public Command {
 private:
  /* Data */

 public:
  Exit();
  ~Exit();
  int execute(int inputFile = 0, int outputFile = 1);
  void setArgumentList(std::vector<std::string> argumentVec);
  const char *const getFilename() { return nullptr; }
  void print(){};
};

#endif