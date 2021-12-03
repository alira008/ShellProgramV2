#ifndef __DOUBLE_OUTPUT_REDIRECTION_CONNECTOR_HPP__
#define __DOUBLE_OUTPUT_REDIRECTION_CONNECTOR_HPP__
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "./connector.hpp"

class DoubleOutputRedirectionConnector : public Connector {
 private:
  int fileFlags = O_CREAT | O_APPEND | O_WRONLY;
  mode_t fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH;

 public:
  DoubleOutputRedirectionConnector() : Connector() {}
  ~DoubleOutputRedirectionConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif