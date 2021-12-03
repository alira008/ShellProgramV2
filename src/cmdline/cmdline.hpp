#ifndef __CMDLINE_HPP__
#define __CMDLINE_HPP__

enum class ExitStatus { Success, Fail, Exit };

class Cmdline {
 private:
  /* data */
 public:
  Cmdline() {}
  virtual ~Cmdline(){};
  virtual int execute(int inputFile, int outputFile) = 0;
  virtual const char *const getFilename() = 0;
  virtual void print() = 0;
};

#endif