#include "./and_connector.hpp"

int AndConnector::execute(int inputFile, int outputFile) {
  return left->execute(inputFile, outputFile) &&
         right->execute(inputFile, outputFile);
}

void AndConnector::print() {
  left->print();
  std::cout << "&& ";
  right->print();
  std::cout << std::endl;
}