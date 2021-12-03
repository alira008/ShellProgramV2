#include "./pipe_connector.hpp"

int PipeConnector::execute(int inputFile, int outputFile) {
  //  Place where we store our pipe file descriptors
  int pipeFds[2];

  //  Create pipe file descriptors
  if (pipe(pipeFds) == -1) assert("Error creating pipe file descriptors");

  //    Execute the left side with our output fd
  if (!left->execute(inputFile, pipeFds[1])) {
    close(pipeFds[0]);
    close(pipeFds[1]);
    return 1;
  };

  close(pipeFds[1]);

  //    Execute the right side with our output fd
  if (!right->execute(pipeFds[0], outputFile)) {
    close(pipeFds[0]);
    close(pipeFds[1]);
    return 1;
  };

  close(pipeFds[0]);
  return 0;
}

void PipeConnector::print() {
  left->print();
  std::cout << "| ";
  right->print();
  std::cout << std::endl;
}