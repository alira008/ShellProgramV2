#include "./or_connector.hpp"

int OrConnector::execute(int inputFile, int outputFile) {
  return left->execute(inputFile, outputFile) ||
         right->execute(inputFile, outputFile);
}

void OrConnector::print() {
  left->print();
  std::cout << "|| ";
  right->print();
  std::cout << std::endl;
}