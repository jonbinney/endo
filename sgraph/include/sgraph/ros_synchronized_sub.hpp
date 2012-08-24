#ifndef SGRAPH_ROS_SYNCHRONIZED_SUB_CELL_
#define SGRAPH_ROS_SYNCHRONIZED_SUB_CELL_

#include <string>
#include <iostream>
#include <sgraph/cell.hpp>


namespace sgraph
{
  class RosSynchronizedSubCell : public Cell
  {
  public:
    RosSynchronizedSubCell() {};

    virtual void declareParams(Ports &params) {
      std::cout << "Hello cell declaring params\n";
    }
    
    virtual void declareIO(Ports &inputs, Ports &outputs) {
      std::cout << "Hello cell declaring IO\n";
      inputs.declare("message", "Message that will be printed");
    }
    
    virtual void setParams(const Ports &params) {}

    virtual void start(void) {}

    virtual void stop(void) {}

    virtual void process(Ports &inputs, Ports &outputs) {
      std::cout << "Hello:" << inputs.get<std::string>("message") << std::endl;
    }

  };
}

#endif /* SGRAPH_ROS_SYNCHRONIZED_SUB_CELL_ */
