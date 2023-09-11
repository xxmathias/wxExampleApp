# Gather all source files in this directory
file(GLOB SRC_FILES "*.cpp")
add_library(app_sources OBJECT ${SRC_FILES})
