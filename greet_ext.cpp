#include <boost/python.hpp>

#include "greet.h"

BOOST_PYTHON_MODULE(greet_ext) { boost::python::def("say_hello", say_hello); }
