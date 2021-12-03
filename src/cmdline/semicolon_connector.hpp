#ifndef __SEMICOLON_CONNECTOR_HPP__
#define __SEMICOLON_CONNECTOR_HPP__
#include <iostream>

#include "./connector.hpp"

class SemicolonConnector : public Connector {
 private:
  /* data */
 public:
  SemicolonConnector() : Connector() {}
  ~SemicolonConnector(){};
  int execute(int inputFile = 0, int outputFile = 1);
  void print();
};

#endif