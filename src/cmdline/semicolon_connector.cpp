#include "./semicolon_connector.hpp"

int SemicolonConnector::execute(int inputFile, int outputFile) {
  //  Execute left side
  left->execute(inputFile, outputFile);

  //  Right exists, also execute the right side
  if (right) right->execute(inputFile, outputFile);

  return true;
}

void SemicolonConnector::print() {
  left->print();
  std::cout << "; ";
  right->print();
  std::cout << std::endl;
}