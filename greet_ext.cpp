#include "greet.h"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(greet_ext) { boost::python::def("say_hello", say_hello); }
