cmake_minimum_required(VERSION 3.5.1)
project(py_ext LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
endif()

# Find necessary packages
find_package( PythonLibs  REQUIRED )
include_directories( ${PYTHON_INCLUDE_DIRS} )

find_package( Boost COMPONENTS python REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

# Build our library
add_library( greet SHARED greet.cpp )

# Define the wrapper library that wraps our library
add_library( greet_ext SHARED greet_ext.cpp)
target_link_libraries( greet_ext ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} greet)
# don't prepend wrapper library name with lib
set_target_properties( greet_ext PROPERTIES PREFIX "" )