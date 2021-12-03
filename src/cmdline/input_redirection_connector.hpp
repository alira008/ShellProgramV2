#ifndef __INPUT_REDIRECTION_CONNECTOR_HPP__
#define __INPUT_REDIRECTION_CONNECTOR_HPP__
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "./connector.hpp"

class InputRedirectionConnector : public Connector {
 private:
  int fileFlags = O_RDONLY;

 public:
  InputRedirectionConnector() : Connector() {}
  ~InputRedirectionConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif