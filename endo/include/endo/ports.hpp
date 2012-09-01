#ifndef ENDO_PORTS_
#define ENDO_PORTS_

#include <string>
#include <vector>
#include <map>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

#include <endo/port.hpp>

namespace endo
{
  class Ports
  {
  public:
    Ports() {};

    void declare(const std::string &port_name, const std::string &port_doc) {
      Port new_port(port_name, port_doc);
      port_vec_.push_back(new_port);
      port_map_.insert(std::pair<std::string, Port>(port_name, new_port));
    }

    template <typename T>
    T getValue(const std::string &port_name) {
      return port_map_.at(port_name).getValue<T>();
    }

    template <typename T>
    void setValue(const std::string &port_name, T &value) {
      port_map_.at(port_name).setValue<T>(value);
    }

  private:
    std::vector<Port> port_vec_;
    std::map<std::string, Port> port_map_;
  };
} /* namespace endo */

#endif /* ENDO_PORTS_ */
