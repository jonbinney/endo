#include <sgraph/cell.hpp>
#include <sgraph/hello_cell.hpp>
#include <iostream>

int main(int argc, char **argv) {
  sgraph::HelloCell hello_cell;
  sgraph::Ports inputs, outputs, params;

  hello_cell.declareParams(params);
  hello_cell.setParams(params);
  hello_cell.declareIO(inputs, outputs);

  inputs.set<std::string>("message", std::string("my message"));
  hello_cell.process(inputs, outputs);

  return 0;
}
