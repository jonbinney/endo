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
  class Ports
  {
  public:
    Ports() {};

    void declare(const std::string &port_name, const std::string &doc) {
      port_names_.push_back(port_name);
      port_docs_[port_name] = doc;
      port_vals_[port_name] = boost::any();
    }

    template <typename T>
    const T get(const std::string &port_name) {
      return boost::any_cast<T>(port_vals_[port_name]);
    }

    template <typename T>
    void set(const std::string &port_name, const T &val) {
      port_vals_[port_name] = val;
    }

  private:
    std::vector<std::string> port_names_;
    std::map<std::string, std::string> port_docs_;
    std::map<std::string, boost::any > port_vals_;
  };


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
