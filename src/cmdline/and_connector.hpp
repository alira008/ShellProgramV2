#ifndef __AND_CONNECTOR_HPP__
#define __AND_CONNECTOR_HPP__
#include <iostream>

#include "./connector.hpp"

class AndConnector : public Connector {
 private:
  /* data */
 public:
  AndConnector() : Connector() {}
  ~AndConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif