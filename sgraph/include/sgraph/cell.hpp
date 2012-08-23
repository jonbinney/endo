#ifndef SGRAPH_CELL_
#define SGRAPH_CELL_

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

namespace sgraph
{
  /* class used for inputs, outputs, and params */
  class Ports
  {
  public:
    Ports() {};

    /* should have a locking version of this */    
    void declare(const std::string &port_name, const std::string &doc) {
      port_names_.push_back(port_name);
      port_docs_[port_name] = doc;
      port_vals_[port_name] = boost::shared_ptr<boost::any>();
    }

    /* should have a locking version of this */
    const boost::shared_ptr<boost::any> &get(const std::string &port_name) {
      return port_vals_[port_name];
    }

    /* should have a locking version of this */
    void set(const std::string &port_name, const boost::shared_ptr<boost::any> &val) {
      port_vals_[port_name] = val;
    }

  private:
    std::vector<std::string> port_names_;
    std::map<std::string, std::string> port_docs_;
    std::map<std::string, boost::shared_ptr<boost::any> > port_vals_;
  };

  /* base class for all cells */
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

#endif /* SGRAPH_CELL_ */
