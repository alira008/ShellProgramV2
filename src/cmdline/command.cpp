#include "./command.hpp"

Command::~Command() {
  for (unsigned i = 0; argumentList[i] != nullptr; ++i) {
    delete[] argumentList[i];
    argumentList[i] = nullptr;
  }
  delete[] argumentList;
  argumentList = nullptr;
}

Command::Command() {}

Command::Command(std::vector<std::string> argumentVec) {
  setArgumentList(argumentVec);
}

void Command::setArgumentList(std::vector<std::string> argumentVec) {
  //  If argument list is not empty, clear it
  if (argumentList != nullptr) {
    std::cout << "Argument list not empty... clearing first" << std::endl;
    for (unsigned i = 0; argumentList[i] != nullptr; ++i) {
      std::cout << argumentList[i] << std::endl;
      delete[] argumentList[i];
      argumentList[i] = nullptr;
    }
    delete[] argumentList;
    argumentList = nullptr;
    std::cout << "Cleared" << std::endl;
  };

  //  Set the size of the char ** to the size of the argumentVec while also
  //  adding room to add \0 at the end of the vector
  argumentList = new char*[argumentVec.size() + 1];
  for (unsigned i = 0; i < argumentVec.size(); ++i) {
    //  Copy the c_str in each element in the vector
    int cstrSize = argumentVec[i].size() + 1;
    argumentList[i] = new char[cstrSize];
    std::strncpy(argumentList[i], argumentVec[i].c_str(), cstrSize);
  }
  //  Add the null ptr at the end of the char **
  argumentList[argumentVec.size()] = nullptr;
}

int Command::execute(int inputFile, int outputFile) {
  //  Status of child
  int status = 0;
  //  Create a child process
  pid_t pid = fork();
  //  Fork fails
  if (pid == -1) {
    assert("Fork failed to create");
  }
  //    Child fork
  else if (pid == 0) {
    //  Duplicate file descriptor for output/input redirection
    if (inputFile != STDIN_FILENO) {
      if (dup2(inputFile, STDIN_FILENO) == -1)
        assert("Error in dup2 inputfile");
      close(inputFile);
    }
    if (outputFile != STDOUT_FILENO) {
      if (dup2(outputFile, STDOUT_FILENO) == -1)
        assert("Error in dup2 outputfile");
      close(outputFile);
    }

    //  Execute commands
    if (execvp(argumentList[0], argumentList) == -1) {
      assert("Error in execvp");
    }
  }
  //    Parent fork
  else {
    //    Parent waits for child process to terminate
    if (wait(&status) == -1)
      assert("Error waiting for child process to terminate");

    //  Returns false if the child does not exit properly
    if (!WIFEXITED(status)) {
      assert("Child process did not terminate properly");
    }
  }

  return !WEXITSTATUS(status);
}

void Command::print() {
  for (unsigned i = 0; argumentList[i] != nullptr; ++i) {
    std::cout << argumentList[i] << " ";
  }
}