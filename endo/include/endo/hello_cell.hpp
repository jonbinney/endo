#ifndef ENDO_HELLO_CELL_
#define ENDO_HELLO_CELL_

#include <string>
#include <iostream>
#include <endo/cell.hpp>

namespace endo
{
  class HelloCell : public Cell
  {
  public:
    HelloCell() {};

    virtual void declareParams(Ports &params) {
      std::cout << "Hello cell declaring params\n";
    }
    
    virtual void declareIO(Ports &inputs, Ports &outputs) {
      std::cout << "Hello cell declaring IO\n";
      inputs.declare("message", "Message that will be printed");
    }
    
    virtual void setParams(const Ports &params) {}

    virtual void process(Ports &inputs, Ports &outputs) {
      std::cout << "Hello:" << inputs.getValue<std::string>("message") << std::endl;
    }

  };
}

#endif /* ENDO_HELLO_CELL_ */
