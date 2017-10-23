cmake_minimum_required (VERSION 3.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -finput-charset=UTF-8 -D_UNICODE -std=c++11 -Wfatal-errors -fPIC")

# debian & ubuntu boost maintainers are responsible for the broken
# naming of python component, so there is no general way to
# link with it on linux. stop by and say wussup to the kids:
# https://bugs.launchpad.net/ubuntu/+source/boost1.53/+bug/1231609
set(PY_COMPONENT "python3") # for normal distributions
if(EXISTS "/etc/debian_version")
  set(PY_COMPONENT "python-py35") # for debian & ubuntu
endif()

# if boost is installed in non-standard directory, set BOOST_ROOT
find_package(Boost 1.55 COMPONENTS ${PY_COMPONENT} REQUIRED)
set(Python_ADDITIONAL_VERSIONS 3.5)
find_package(PythonLibs)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(morpher main.cxx)
target_link_libraries(morpher LINK_PRIVATE ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
