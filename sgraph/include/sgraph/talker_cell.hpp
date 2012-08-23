#ifndef SGRAPH_TALKER_CELL_
#define SGRAPH_TALKER_CELL_

#include <boost/any.hpp>

#include <sgraph/cell.hpp>

namespace sgraph
{
  class TalkerCell: Public Cell
  {
  public:
    TalkerCell() {};

    void declareParams(params) {};

    virtual void declareIO(params, in, out) {
      out.declare("words", "Some words");
    };

    virtual void process(in, out) {};


  };
}

#endif /* SGRAPH_TALKER_CELL_ */
