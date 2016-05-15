cmake_minimum_required(VERSION 3.5)
project(acm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 2008.cpp 2009.cpp 2010.cpp 2011.cpp 2012.cpp 2013.cpp 2014.cpp 2015.cpp 2016.cpp 2017.cpp tast.cpp SimpleProject/2018.cpp SimpleProject/x001.cpp SimpleProject/x002.cpp SimpleProject/x003.cpp SimpleProject/x004.cpp SimpleProject/x005.cpp SimpleProject/x006.cpp SimpleProject/x007.cpp SimpleProject/poj2255.cpp)
add_executable(acm ${SOURCE_FILES})