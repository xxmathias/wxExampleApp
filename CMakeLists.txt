cmake_minimum_required(VERSION 3.18)
project(name VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -pthread")

# Include directories for wxWidgets
include_directories(/usr/lib/x86_64-linux-gnu/wx/include/gtk3-unicode-3.0)
include_directories(/usr/include/wx-3.0)

# Define wxWidgets libraries
set(WX_LIBS
    -lwx_gtk3u_xrc-3.0
    -lwx_gtk3u_html-3.0
    -lwx_gtk3u_qa-3.0
    -lwx_gtk3u_adv-3.0
    -lwx_gtk3u_core-3.0
    -lwx_baseu_xml-3.0
    -lwx_baseu_net-3.0
    -lwx_baseu-3.0
)

include(CTest)

set(CPP_SRCS  # all non-main source files
  unit.cpp
)

add_library(catch2 catch_amalgamated.cpp)

add_executable(unit_test unit.cpp unit_test.cpp)
target_link_libraries(unit_test catch2)
add_test(NAME unit_test COMMAND unit_test)

  