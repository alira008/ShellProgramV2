#include "./input_redirection_connector.hpp"

int InputRedirectionConnector::execute(int inputFile, int outputFile) {
  //    Open the file given on the right side
  outputFile = open(right->getFilename(), fileFlags);

  if (outputFile < -1)
    assert("Error opening file for double output redirection");

  //  Execute commands
  int retStatus = left->execute(inputFile, outputFile);

  //  Close open file after execution is done
  if (close(outputFile) == -1)
    assert("Error closing file for double output redirection");

  return retStatus;
}

void InputRedirectionConnector::print() {
  left->print();
  std::cout << "< ";
  right->print();
  std::cout << std::endl;
}