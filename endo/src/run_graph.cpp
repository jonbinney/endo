#include <endo/cell.hpp>
#include <endo/ports.hpp>
#include <endo/hello_cell.hpp>
#include <iostream>

int main(int argc, char **argv) {
  endo::HelloCell hello_cell;
  endo::Ports inputs, outputs, params;

  hello_cell.declareParams(params);
  hello_cell.setParams(params);
  hello_cell.declareIO(inputs, outputs);

  inputs.set<std::string>("message", std::string("my message"));
  hello_cell.process(inputs, outputs);

  return 0;
}
