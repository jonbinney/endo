#ifndef ENDO_CELL_
#define ENDO_CELL_

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

namespace endo
{



  class Cell
  {
  public:
    Cell(void) {};

    virtual void declareParams(Ports &params) = 0;

    virtual void setParams(const Ports &params) = 0;

    virtual void declareIO(Ports &inputs, Ports &outputs) = 0;

    virtual void process(Ports &inputs, Ports &outputs) = 0;

  };

}

#endif /* ENDO_CELL_ */
