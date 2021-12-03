#ifndef __CMDLINE_COMPOSITE_HPP__
#define __CMDLINE_COMPOSITE_HPP__
#include <string>
#include <vector>

#include "./and_connector.hpp"
#include "./cmdline.hpp"
#include "./command.hpp"
#include "./connector.hpp"
#include "./double_output_redirection_connector.hpp"
#include "./exit.hpp"
#include "./input_redirection_connector.hpp"
#include "./or_connector.hpp"
#include "./pipe_connector.hpp"
#include "./semicolon_connector.hpp"
#include "./single_output_redirection_connector.hpp"

class CmdlineComposite : public Cmdline {
 private:
  Cmdline* cmdlineTree = nullptr;
  void buildTree(std::vector<std::vector<std::string>> commandList);
  bool isConnector(std::string arg);
  Connector* makeConnector(std::string arg);

 public:
  CmdlineComposite(std::vector<std::vector<std::string>> commandList);
  ~CmdlineComposite();
  int execute(int inputFile = 0, int outputFile = 1);
  const char* const getFilename() { return nullptr; }
  void print() {}
};

#endif