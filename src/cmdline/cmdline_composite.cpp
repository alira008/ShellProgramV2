#include "./cmdline_composite.hpp"

CmdlineComposite::CmdlineComposite(
    std::vector<std::vector<std::string>> commandList) {
  buildTree(commandList);
}

CmdlineComposite::~CmdlineComposite() {
  delete cmdlineTree;
  cmdlineTree = nullptr;
};

bool CmdlineComposite::isConnector(std::string arg) {
  const std::vector<std::string> connectors = {"&&", "||", ";", "<",
                                               ">",  ">>", "|"};
  for (auto connector : connectors) {
    if (arg == connector) return true;
  }
  return false;
}

Connector *CmdlineComposite::makeConnector(std::string arg) {
  if (arg == "&&")
    return new AndConnector;
  else if (arg == "||")
    return new OrConnector;
  else if (arg == ";")
    return new SemicolonConnector;
  else if (arg == "<")
    return new InputRedirectionConnector;
  else if (arg == ">")
    return new SingleOutputRedirectionConnector;
  else if (arg == ">>")
    return new DoubleOutputRedirectionConnector;
  else if (arg == "|")
    return new PipeConnector;
  else
    return nullptr;
}

void CmdlineComposite::buildTree(
    std::vector<std::vector<std::string>> commandList) {
  std::vector<Cmdline *> cmds;
  for (std::vector<std::string> command : commandList) {
    if (!isConnector(command[0])) {
      Cmdline *cmd;
      if (command[0] == "exit") {
        cmd = new Exit();
      } else {
        cmd = new Command(command);
      }
      cmds.push_back(cmd);
    } else {
      Connector *connector = makeConnector(command[0]);
      if (!cmds.empty()) {
        connector->setRight(cmds.back());
        cmds.pop_back();
      }
      if (!cmds.empty()) {
        connector->setLeft(cmds.back());
        cmds.pop_back();
      }

      //    Finally push connector into cmds
      cmds.push_back(connector);
    }
  }
  if (!cmds.empty()) {
    cmdlineTree = cmds.back();
    cmds.pop_back();
  }
}

int CmdlineComposite::execute(int inputFile, int outputFile) {
  //   cmdlineTree->print();
  return cmdlineTree->execute(inputFile, outputFile);
}