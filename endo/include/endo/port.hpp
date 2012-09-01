#ifndef ENDO_PORT_
#define ENDO_PORT_

#include <string>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

namespace endo
{
  class Port
  {
  public:
    Port(const std::string &name, const std::string &doc)
      : name_(name), doc_(doc) {}
    
    template <typename T>
    void setValue(const T &value) {
      value_ = value;
    }
    
    template <typename T>
    T getValue() {
      return boost::any_cast<T>(value_);
    }
    
    std::string getName() {return name_;}
    
    std::string getDoc() {return doc_;}
    
  private:
    std::string name_;
    std::string doc_;
    boost::any value_;
  };

} /* namespace endo */

#endif /* ENDO_PORT_ */
