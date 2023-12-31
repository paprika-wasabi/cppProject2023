#include "./Checker.hpp"
#include "./Parse.hpp"
#include "./Solver.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char **argv) {
  Checker c;
  // Parse the command-line arguments.
  if (argc != 4) {
    std::cout << "Usage: ./Main [.options] [.constraints] [.models]"
              << std::endl;
    std::exit(1);
  }

  std::string optionFile = argv[1];
  std::string constraintsFile = argv[2];
  std::string modelsFile = argv[3];
  c.readDataInput(optionFile, constraintsFile);
  c.readDataModel(modelsFile);
  if (!c.ifOptionAndConstraints()) {
    return c.errorCode_;
  }
  if (!c.ifModel()) {
    return c.errorCode_;
  }
  return 0;
}