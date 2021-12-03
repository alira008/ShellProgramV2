#ifndef __SINGLE_OUTPUT_REDIRECTION_CONNECTOR_HPP__
#define __SINGLE_OUTPUT_REDIRECTION_CONNECTOR_HPP__
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "./connector.hpp"

class SingleOutputRedirectionConnector : public Connector {
 private:
  int fileFlags = O_CREAT | O_TRUNC | O_WRONLY;
  mode_t fileMode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH;

 public:
  SingleOutputRedirectionConnector() : Connector() {}
  ~SingleOutputRedirectionConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif