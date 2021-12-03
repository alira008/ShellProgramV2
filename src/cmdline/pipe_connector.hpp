#ifndef __PIPE_CONNECTOR_HPP__
#define __PIPE_CONNECTOR_HPP__
#include <unistd.h>

#include <iostream>

#include "./connector.hpp"

class PipeConnector : public Connector {
 private:
  /* data */
 public:
  PipeConnector() : Connector() {}
  ~PipeConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif