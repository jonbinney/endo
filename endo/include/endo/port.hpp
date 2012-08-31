#ifndef ENDO_CELL_
#define ENDO_CELL_

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
    setValue(const boost::shared_ptr<const T> &value)
    {
      value_ = value;
    }

    template <typename T>
    boost::shared_ptr<const T> getValue()
    {
      return boost::any_cast<boost::shared_ptr<const T> >(value_);
    }

  private:
    std::string name_;
    std::string doc_;
    boost::any value_;
  };

} /* namespace endo */
