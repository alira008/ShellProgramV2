#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__
#include "./cmdline.hpp"

class Connector : public Cmdline {
 protected:
  Cmdline* left = nullptr;
  Cmdline* right = nullptr;

 public:
  Connector() : left(nullptr), right(nullptr) {}
  ~Connector() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
  };
  virtual int execute(int inputFile, int outputFile) = 0;
  virtual void print() = 0;
  void setLeft(Cmdline*& cmd) { left = cmd; };
  void setRight(Cmdline*& cmd) { right = cmd; };
  const char* const getFilename() { return nullptr; }
};

#endif