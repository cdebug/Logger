cmake_minimum_required(VERSION 3.10)
#project name
project(logger)
SET(LINK_TARGETNAME logger)
#set c++11 library
set( CMAKE_CXX_FLAGS "-std=c++11" )
#set debug mode
set( CMAKE_BUILD_TYPE "Debug" )
# 编译生成调试版本
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#headers directories
include_directories(/usr/local/include)
include_directories(include/muduo)

#设置变量，表示所有的源文件
add_subdirectory(include/muduo)
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR}/src LINK_SOURCEFILES)

link_directories(/usr/local/lib)
SET(LINK_LIB_LIST muduo)

ADD_EXECUTABLE(${LINK_TARGETNAME}  ${LINK_SOURCEFILES})

FIND_LIBRARY(RUNTIME_LIB rt /usr/lib  /usr/local/lib NO_DEFAULT_PATH)
TARGET_LINK_LIBRARIES(${LINK_TARGETNAME} ${LINK_LIB_LIST})