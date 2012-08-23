#include <sgraph/cell.hpp>
#include <sgraph/hello_cell.hpp>
#include <iostream>

using namespace sgraph;

int main(int argc, char **argv) {
  sgraph::HelloCell hello_cell;
  sgraph::Ports inputs, outputs, params;

  hello_cell.declareParams(params);
  hello_cell.setParams(params);
  hello_cell.declareIO(inputs, outputs);


  boost::make_shared(

  hello_cell.process(inputs, outputs);

  return 0;
}
