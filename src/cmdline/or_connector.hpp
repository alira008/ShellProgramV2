#ifndef __OR_CONNECTOR_HPP__
#define __OR_CONNECTOR_HPP__
#include <iostream>

#include "./connector.hpp"

class OrConnector : public Connector {
 private:
  /* data */
 public:
  OrConnector() : Connector() {}
  ~OrConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif